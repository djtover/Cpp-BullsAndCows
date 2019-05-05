/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
// #include "calculate.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {
	
	badkan::TestCase testcase;
	int grade=0;
	int right=0;
	int wrong = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

		// My tests
		testcase.setname("valid input for calculate for just bulls")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1111"), "1,0") 
	  .CHECK_OUTPUT(calculateBullAndPgia("1234","1256"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1235"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5674"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5634"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5234"), "3,0")
		;
		testcase.setname("valid input for calculate for just cows")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4") 
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4325"), "0,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4356"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4567"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5467"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5426"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5421"), "0,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","3421"), "0,4")
		;
		testcase.setname("valid input for calculate for bulls and cows")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1324"), "2,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4231"), "2,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1243"), "2,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1423"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4213"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4132"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","3124"), "1,3")
		;
	

		testcase.setname("repeating digits in guess")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1123"),"1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1122"),"1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1223"),"2,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1112"),"1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1233"),"3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1442"),"1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1114"),"2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4411"),"0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","3232"),"2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4334"),"2,0")
		;

		testcase.setname("repeating digits in choose")
		.CHECK_OUTPUT(calculateBullAndPgia("1134","1234"),"3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1224","1234"),"3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1212","1234"),"2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4411","1234"),"0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("3223","1234"),"1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("3314","1234"),"1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("2234","1234"),"3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4224","1234"),"2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("2342","1234"),"0,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1323","1234"),"1,2")
		;
		testcase.setname("repeating digits in both")
		.CHECK_OUTPUT(calculateBullAndPgia("1134","1123"),"2,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1224","1122"),"2,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1212","1223"),"2,1")
		.CHECK_OUTPUT(calculateBullAndPgia("4411","1112"),"1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("3223","1233"),"2,1")
		.CHECK_OUTPUT(calculateBullAndPgia("3314","1442"),"0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("2234","1114"),"1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4224","4411"),"1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("2342","3232"),"1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1323","4334"),"1,1")
		;

		testcase.setname("valid input for choose")
		.CHECK_OUTPUT(c1234.choose(4),"1234")
		.CHECK_OUTPUT(c12345.choose(5),"12345")
		.CHECK_OUTPUT(c9999.choose(4),"9999")
		;

		testcase.setname("valid input for guesser")
		.CHECK_OUTPUT(g1234.guess(),"1234")
		.CHECK_OUTPUT(g12345.guess(),"12345")
		.CHECK_OUTPUT(g9999.guess(),"9999")
		;

	testcase.setname("testing smartguesser within 34 guesses");
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 10, 251)<=251, true);  // smarty should always win in at most 10 turns!
		}

		testcase.setname("testing smartguesser within 34 guesses");
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 23)<=23, true);  // smarty should always win in at most 10 turns!
		}

		testcase.setname("testing smartguesser within 16 guesses");
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 3, 15)<=15, true);  // smarty should always win in at most 10 turns!
		}
		testcase.setname("testing smartguesser within 14 guesses");
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 2, 12)<=12, true);  // smarty should always win in at most 10 turns!
		}
		testcase.setname("testing smartguesser within 10 guesses");
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 1, 10)<=10, true);  // smarty should always win in at most 10 turns!
		}
		


 
    grade = testcase.grade();
		right = testcase.right();
		wrong = testcase.wrong();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "\nYour grade is: "  << grade <<"\nRight: "<< right << "\nWrong: "<< wrong <<endl;
	return 0;
}

