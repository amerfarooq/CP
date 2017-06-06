//============================================================================
// Name        : NeuronNetwork.cpp
// Author      : Amer Farooq
// Version     : 1
// Copyright   : Your copyright notice
// Description : Main for NeuralNetwork
//============================================================================

#include "ComplexCumulativeNeuron.h"
#include "ComplexNeuron.h"
#include "CumulativeNeuron.h"

int main() {

//	 Test of  part 1
	cout << "===== Test of 1st part  =====" << endl << endl;

	Neuron neuron1(0, 1, 0.5);
	Neuron neuron2(1, 0, 1.0);
	Neuron neuron3(1, 1, 2.0);

	neuron1 += &neuron2;
	neuron1 += &neuron3;
	neuron2 += &neuron3;

	cout << neuron1 << endl;

	neuron1.fire(10);
	cout << "Signals :" << endl;
	cout << neuron1.signal() << endl;
	cout << neuron2.signal() << endl;
	cout << neuron3.signal() << endl;

	// Test of  part 2
	cout << endl << "===== Test of 2nd part =====" << endl << endl;

	CumulativeNeuron neuron4(0, 0, 0.75);
	cout << neuron4 << endl;
	neuron4.fire(10);
	neuron4.fire(10);
	cout << "Signal :" << endl;
	cout << neuron4.signal() << endl;

	// Test of Logical OR Gate----------------------------------------------
	cout << "\n===== Test of Logical gate \"OR\" =====" << endl << endl;

	Neuron n0(2, 0, -10);
	Neuron n1(1, 0, 20.0);
	Neuron n2(0, 0, 20.0);

	CumulativeNeuron n3(1, 3, 1);

	n0+=&n3;
	n1+=&n3;
	n2+=&n3;

	n0.fire(1);
	n1.fire(0);
	n2.fire(1);
	cout<< "If a=0 and b=1 then a|b == " << n3;

	n0.fire(1);
	n1.fire(1);
	n2.fire(1);
	cout<< "If a=1 and b=1 then a|b == " << n3;

	n0.fire(1);
	n1.fire(0);
	n2.fire(0);
	cout<< "If a=0 and b=0 then a|b == " << n3;


	// Test of Logical AND Gate-----------------------------------------------
	cout << "\n===== Test of Logical gate \"AND\" =====" << endl << endl;

	Neuron n4(2, 0, -30);
	Neuron n5(1, 0, 20.0);
	Neuron n6(0, 0, 20.0);

	CumulativeNeuron n7(1, 3, 1);

	n4+=&n7;
	n5+=&n7;
	n6+=&n7;

	n4.fire(1);
	n5.fire(0);
	n6.fire(1);
	cout<< "If a=0 and b=1 then a&b == " << n7;

	n4.fire(1);
	n5.fire(1);
	n6.fire(1);
	cout<< "If a=1 and b=1 then a&b == " << n7;

	n4.fire(1);
	n5.fire(0);
	n6.fire(0);
	cout<< "If a=0 and b=0 then a&b == " << n7;

	// Test of Logical NOT Gate-------------------------------------------------
	cout << "\n===== Test of Logical gate \"NOT\" =====" << endl << endl;

	Neuron n8(2, 0, 10);
	Neuron n9(1, 0, -20.0);

	CumulativeNeuron n10(1, 3, 1);

	n8+=&n10;
	n9+=&n10;

	n8.fire(1);
	n9.fire(0);
	cout<< "If A = 0, not A = " << n10;

	n8.fire(1);
	n9.fire(1);
	cout<< "If A = 1, not A = " << n10;

	// Test of Logical NOT and AND Gate-------------------------------------------
	cout << "\n===== Test of Logical gate \"NOT & AND\" =====" << endl << endl;

	Neuron n11(2, 0, 10);
	Neuron n12(1, 0, -20.0);
	Neuron n13(0, 0, -20.0);

	CumulativeNeuron n14(1, 3, 1);

	n11+=&n14;
	n12+=&n14;
	n13+=&n14;

	n11.fire(1);
	n12.fire(0);
	n13.fire(1);
	cout<< "If a=0 and b=1 then ~a & ~b == " << n14;

	n11.fire(1);
	n12.fire(1);
	n13.fire(1);
	cout<< "If a=1 and b=1 then ~a & ~b == " << n14;

	n11.fire(1);
	n12.fire(0);
	n13.fire(0);
	cout<< "If a=0 and b=0 then ~a & ~b == " << n14;

	// Test of XNOR Gate-------------------------------------------
	cout << "\n===== Test of Logical gate \"XNOR\" =====" << endl << endl;

	ComplexNeuron x0(2, 0);
	ComplexNeuron x1(1, 0); // x1 as input
	ComplexNeuron x2(0, 0); // x2 as inpu

	ComplexCumulativeNeuron x3(1, 3, 1);
	ComplexCumulativeNeuron x4(0, 3, 1);
	ComplexNeuron x6(3, 3, 1);

	ComplexCumulativeNeuron x5(6, 2, 1);

	// layer-1 neurons

	x0.attach(-30, &x3);
	x0.attach(10, &x4);

	x1.attach(20, &x3);
	x1.attach(-20, &x4);

	x2.attach(20, &x3);
	x2.attach(-20, &x4);

	// layer-2 neurons

	x6.attach(-10, &x5);

	x3.attach(20, &x5);
	x4.attach(20, &x5);

	x0.fire(1);
	x6.fire(1);

	// Lets start checking the system by calling the fire method of input neurons
	x1.fire(0);
	x2.fire(1);

	cout<< "If a=0 and b=1 then ˜(aˆb) == " << x5 << endl;

	x0.fire(1);
	x6.fire(1);

	x1.fire(1);
	x2.fire(1);

	cout<< "If a=1 and b=1 then ˜(aˆb) == " << x5 << endl;

	x0.fire(1);
	x6.fire(1);

	x1.fire(0);
	x2.fire(0);
	cout<< "If a=0 and b=0 then ˜(aˆb) == " << x5 << endl;

}
