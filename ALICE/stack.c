#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

void initStack(stack* sp, int n){
	sp->top = n;
}

double topValue(stack* sp){
	double ans;
	if(sp->top == N){
		ans = sqrt(-1.0);
	}else{
		ans = sp->data[sp->top];
	}
	return ans;
	
}

void push(stack* sp, double v){
	sp->data[sp->top-1] = v;
	sp->top = sp->top - 1;
}

double pull(stack *sp){
	double ans;
	if(sp->top == N){
		ans = sqrt(-1.0);
	}else{
		ans = sp->data[sp->top];
		sp->top ++;
	}
	return ans;
}

void printStack(stack *sp){
	int i;
	for(i = N - 1; i >= sp->top; i--){
		printf("%f\n", sp->data[i]);
	}
}

void addStack(stack *sp){
	push(sp, pull(sp) + pull(sp));
}


void subStack(stack	*sp){
	double x1, x2;
	x1 = pull(sp);
	x2 = pull(sp);
	push(sp, x2 - x1);
}

void divStack(stack	*sp){
	double x1, x2;
	x1 = pull(sp);
	x2 = pull(sp);
	push(sp, x2 / x1);
}

void mulStack(stack *sp){
	push(sp, pull(sp) * pull(sp));
}



fusion input(){
	int number;
	double mass;
	fusion myFusion;

	fprintf(stderr, "What reaction do you want to do ? Please Enter number.\n(1) D-D1 \n(2) D-D2 \n(3) D-T \n(4) D-^3He\n");
    scanf("%d", &number);
    fprintf(stderr, "How much fuel(kg) would you like to use to do Nuclear Fusion ?\n");
    scanf("%lf", &mass);

    	if(number == 1) {
        	printf("Reaction formula：D + D　→　T + p(3.03 MeV)\n");
          	myFusion.number = number;
          	myFusion.mass = mass;
        }

        if(number == 2) {
        	printf("Reaction formula：D + D　→　^3He + n(2.34 MeV)\n");
        	myFusion.number = number;
          	myFusion.mass = mass;	
        }

        if (number == 3) {
            printf("Reaction formula：D + T　→　^4He + n(14 MeV)\n");
            myFusion.number = number;
          	myFusion.mass = mass;
        }

        if (number == 4) {
            printf("Reaction formula：D + ^3He → ^4He + p(14.7 MeV)\n");
            myFusion.number = number;
          	myFusion.mass = mass;
 	    
 	    }

 	    return myFusion;
 	   
 }

 double fusionEne(fusion myFusion){
 		double x, y, z, w, m, E;
 		if(myFusion.number == 1) {
        	x = D;
        	y = D;
        	z = T;
        	w = proton; 
        }

        if(myFusion.number == 2) {
        	x = D;
        	y = D;
        	z = He3;
        	w = neutron; 	
        }

        if (myFusion.number == 3) {
            x = D;
        	y = T;
        	z = He4;
        	w = neutron; 
        }

        if (myFusion.number == 4) {
            x = D;
        	y = He3;
        	z = He4;
        	w = proton; 
 	    
 	    }

 	    m = (x + y - z - w) * myFusion.mass / (x + y);
		E = m * c * c;  //E = Δmc^2

 	    return E;
 }

conv conversion(double E){
	conv myConv;
	
    myConv.toe = E / TOE;
    myConv.tnt = E / TNT;
    myConv.lb = E / LB;
    myConv.aec = E / AEC;
        

 	return myConv;
}


double sv(fusion myFusion){
    double x, y, z, rwf, sv;
    if(myFusion.number == 1) {
        x = D;
        y = D;
        z = DD1MeV;
        rwf = pRwf;
        
    }
    
    if(myFusion.number == 2) {
        x = D;
        y = D;
        z = DD2MeV;
        rwf = nRwf;
    }
    
    if (myFusion.number == 3) {
        x = D;
        y = T;
        z = DTMeV;
        rwf = nRwf;
    }
    
    if (myFusion.number == 4) {
        x = D;
        y = He3;
        z = D3HeMeV;
        rwf = pRwf;
        
    }
    
    sv = (z * electron * myFusion.mass * rwf) / (W * (x + y));
    
    return sv;
	
}

void output(double E, conv myConv, double sv){

	printf("Generation rate of Energy：%lg J\n", E);
	printf("- is equevalent to petroleum %lg t\n", myConv.toe);
	printf("- is equevalent to TNT %lg t\n", myConv.tnt);
	printf("- is equevalent to 'Little Boy' %lg pcs.\n", myConv.lb);
	printf("- is equevalent to annual energy consumption of Japan %lg times\n", myConv.aec);
	printf("Effective dose : %lg Sv(%lg mSv)(anuual limit is 1 mSv)\n\n", sv, sv*1E3);
}

/*
void ALICE(){
    char Yome[100] = "アリス"; //
        char Situgi[100];

        fprintf(stderr, "こんにちは。私は%s。なにを致しましょうか？\n\n",Yome);
        scanf("%[^\n]",Situgi);
        

        char Tenpure[100] = "あなたは誰";
        if(strcmp(Situgi,Tenpure)==0) {
            printf("私は%sです。\n",Yome);
        }


        char Tenpure2[100] = "";    //ご自由にカスタマイズできます。
        if (strcmp(Situgi,Tenpure2)==0) {
            printf("\n");
           
        }

}
*/




