#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "testCommon.h"

void testInitStack(){
	stack myStack;
    testStart("initStack");
    myStack.top = 0.0; 
    initStack(&myStack, N);
    assertEqualsInt(myStack.top, N);
}

void testTopValue(){
	stack myStack;
	double ans;
	testStart("topValue");
	initStack(&myStack, N);
	ans = topValue(&myStack);
	assertEqualsInt(isnan(ans), 1);
	
	myStack.top = N-1;
	myStack.data[N-1] = M_PI;
	ans = topValue(&myStack);
	assertEqualsDouble(ans, M_PI);
	
	myStack.top = N-2;
	myStack.data[N-2] = 1.5;
	ans = topValue(&myStack);
	assertEqualsDouble(ans, 1.5);
}

void testPush(){
	stack myStack;
    testStart("push");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    assertEqualsDouble(topValue(&myStack), M_PI);
    assertEqualsInt(myStack.top, N-1);
    push(&myStack, 1.5);
    assertEqualsDouble(topValue(&myStack), 1.5);
    assertEqualsInt(myStack.top, N-2);
}

void testPull(){
	stack myStack;
    testStart("pull");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    assertEqualsDouble(pull(&myStack), 1.5);
    assertEqualsDouble(pull(&myStack), M_PI);
    assertEqualsInt(isnan(pull(&myStack)), 1);
}

void testPrintStack(){
	stack myStack;
    testStart("printStack");
    printf("テスト1\n");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    printStack(&myStack);
    
    printf("テスト2\n");
    push(&myStack, 1.6);
    push(&myStack, 1.5);
    push(&myStack, 1.4);
    push(&myStack, 1.3);
    printStack(&myStack);
}

void testAddStack(){
	stack myStack;
	
    testStart("addStack");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    addStack(&myStack);
    assertEqualsDouble(topValue(&myStack), M_PI + 1.5);
    assertEqualsInt(myStack.top, N-1);
    
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
   
    initStack(&myStack, N);
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    assertEqualsInt(myStack.top, N-1);
}

void testSubStack(){
    stack myStack;
    //test1個目
    testStart("testSubStack");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    subStack(&myStack);
    assertEqualsDouble(topValue(&myStack), M_PI - 1.5);
    assertEqualsInt(myStack.top, N-1);
    //test2個目(値が一個だけのの時)
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    //test3個目(値が0個の時)
    initStack(&myStack, N);
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    assertEqualsInt(myStack.top, N-1);
}

void testDivStack(){
    stack myStack;
    testStart("testDivStack");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    divStack(&myStack);
    assertEqualsDouble(topValue(&myStack), M_PI / 1.5);
    assertEqualsInt(myStack.top, N-1);
    //test2個目(値が一個だけのの時)
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    //test3個目(値が0個の時)
    initStack(&myStack, N);
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    assertEqualsInt(myStack.top, N-1);
}

void testMulStack(){
    stack myStack;
    //test1個目
    testStart("mulStack");
    initStack(&myStack, N);
    push(&myStack, M_PI);
    push(&myStack, 1.5);
    mulStack(&myStack);
    assertEqualsDouble(topValue(&myStack), M_PI * 1.5);
    assertEqualsInt(myStack.top, N-1);
    //test2個目(値が一個だけのの時)
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    //test3個目(値が0個の時)
    initStack(&myStack, N);
    addStack(&myStack);
    assertEqualsInt(isnan(topValue(&myStack)), 1);
    assertEqualsInt(myStack.top, N-1);
}

/*
void testInput(){
	fusion myFusion;
	int test1;
	double test2;
	testStart("input");
	test1 = 1;
	test2 = 1;
	printf("\x1b[31m最初は1,二つ目は1と入力してください！\x1b[m\n");
	myFusion = input();
	assertEqualsInt(test1, myFusion.number);
	assertEqualsDouble(test2, myFusion.mass);
	test1 = 2;
	test2 = 2;
	printf("\x1b[31m最初は2,二つ目は2と入力してください！\x1b[m\n");
	myFusion = input();
	assertEqualsInt(test1, myFusion.number);
	assertEqualsDouble(test2, myFusion.mass);
	test1 = 3;
	test2 = 3;
	printf("\x1b[31m最初は3,二つ目は3と入力してください！\x1b[m\n");
	myFusion = input();
	assertEqualsInt(test1, myFusion.number);
	assertEqualsDouble(test2, myFusion.mass);
	test1 = 4;
	test2 = 4;
	printf("\x1b[31m最初は4,二つ目は4と入力してください！\x1b[m\n");
	myFusion = input();
	assertEqualsInt(test1, myFusion.number);
	assertEqualsDouble(test2, myFusion.mass);
}
*/

void testFusionEne(){
	fusion myFusion;

	double E, m;
	testStart("fusionEne");
	myFusion.number = 1;
	myFusion.mass = 1E-3;
	E = 0;
	E = fusionEne(myFusion);
	m = (D + D - T - proton) * myFusion.mass / (D + D);
	assertEqualsDouble(sqrt(E/m), c);
	
	myFusion.number = 2;
	myFusion.mass = 2E-3;
	E = 0;
	E = fusionEne(myFusion);
	m = (D + D - He3 - neutron) * myFusion.mass / (D + D);
	assertEqualsDouble(sqrt(E/m), c);
	
	myFusion.number = 3;
	myFusion.mass = 3E-3;
	E = 0;
	E = fusionEne(myFusion);
	m = (D + T - He4 - neutron) * myFusion.mass / (D + T);
	assertEqualsDouble(round(sqrt(E/m)), c);
	
	myFusion.number = 4;
	myFusion.mass = 4E-3;
	E = 0;
	E = fusionEne(myFusion);
	m = (D + He3 - He4 - proton) * myFusion.mass / (D + He3);
	assertEqualsDouble(round(sqrt(E/m)), c);
}

void testConversion(){
	fusion myFusion;
	conv myConv;
	double E;
	testStart("conversion");
	myFusion.number = 1;
	myFusion.mass = 1E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	assertEqualsDouble(myConv.toe * TOE, E);
	assertEqualsDouble(myConv.tnt * TNT, E);
	assertEqualsDouble(myConv.lb * LB, E);
	assertEqualsDouble(myConv.aec * AEC, E);
	
	myFusion.number = 2;
	myFusion.mass = 2E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	assertEqualsDouble(myConv.toe * TOE, E);
	assertEqualsDouble(myConv.tnt * TNT, E);
	assertEqualsDouble(myConv.lb * LB, E);
	assertEqualsDouble(myConv.aec * AEC, E);
	
	myFusion.number = 3;
	myFusion.mass = 1E-3;
	E = roundf(fusionEne(myFusion)); //MacとWindowsで小数点第4位以下の値が違うので丸める。
	myConv = conversion(E);
	assertEqualsDouble(myConv.toe * TOE, E); 
	assertEqualsDouble(myConv.tnt * TNT, E);
	assertEqualsDouble(myConv.lb * LB, E);
	assertEqualsDouble(myConv.aec * AEC, E);
	
	myFusion.number = 4;
	myFusion.mass = 4E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	assertEqualsDouble(myConv.toe * TOE, E);
	assertEqualsDouble(myConv.tnt * TNT, E);
	assertEqualsDouble(myConv.lb * LB, E);
	assertEqualsDouble(myConv.aec * AEC, E);
}


void testSv(){
	double e;
    fusion myFusion;
    testStart("sv");
    //myFusion.number = 1のとき
    myFusion.mass = 1E-3;
    e = roundf(sv(myFusion) * (W * (D + D))  / (DD1MeV * myFusion.mass * pRwf));
    assertEqualsDouble(e, roundf(electron));
    //printf("%lf, %lf\n", e, electron);
    
    //myFusion.number = 2のとき
    myFusion.mass = 2E-3;
    e = roundf(sv(myFusion) * (W * (D + D)) / (DD2MeV * myFusion.mass * nRwf));
    assertEqualsDouble(e, roundf(electron));
    //printf("%lf, %lf\n", e, electron);
    
    //myFusion.number = 3のとき
    myFusion.mass = 3E-3;
    e = roundf(sv(myFusion) * (W * (D + T)) / (DTMeV * myFusion.mass * nRwf));
    assertEqualsDouble(e, roundf(electron));
    //printf("%lf, %lf\n", e, electron);
    
    //myFusion.number = 4のとき
    myFusion.mass = 4E-3;
    e = roundf(sv(myFusion) * (W * (D + He3)) / (D3HeMeV * myFusion.mass * pRwf));
    assertEqualsDouble(e, roundf(electron));
    //printf("%lf, %lf\n", e, electron);
}

void testOutput(){
	fusion myFusion;
	conv myConv;
	double E, SV;

	testStart("output");
	myFusion.number = 1;
	myFusion.mass = 1E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	SV = sv(myFusion);
	output(E, myConv, SV);
	
	myFusion.number = 2;
	myFusion.mass = 2E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	SV = sv(myFusion);
	output(E, myConv, SV);

	myFusion.number = 3;
	myFusion.mass = 3E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	SV = sv(myFusion);
	output(E, myConv, SV);

	myFusion.number = 4;
	myFusion.mass = 4E-3;
	E = fusionEne(myFusion);
	myConv = conversion(E);
	SV = sv(myFusion);
	output(E, myConv, SV);


}


int main(){
    testInitStack();
    testTopValue();
    testPush();
    testPull();
    testPrintStack();
    testAddStack();
    testSubStack();
    testDivStack();
    testMulStack();
    testFusionEne();
    testConversion();
    testSv();
    testOutput();

    testErrorCheck(); // これは消さないこと

    return 0;
}

