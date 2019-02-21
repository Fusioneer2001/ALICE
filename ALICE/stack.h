#ifndef stack_h
#define stack_h

#define N 10000
//#define NA 6.022140857E23 //アボガドロ数
#define D 3.344494636E-27 //重水素の質量
#define T 5.008267443E-27 //三重水素の質量
#define He3 5.00823443E-27 //ヘリウム3の質量
#define He4 6.646478965E-27 //ヘリウム4の質量
#define neutron 1.674927471E-27 //中性子の質量
#define proton 1.672621898E-27 //陽子の質量
#define electron 1.6021766208E-19 //電気素量
#define c 299792458 //光速度 
#define TOE 41.868E9 //石油換算トン
#define AEC 15E15 //日本の年間消費エネルギー
#define TNT 4.184E9 //TNT換算
#define LB 6.276E13 //広島型原爆換算
#define pRwf 2.0 //陽子線の放射線加重係数
#define nRwf 10.0 //中性子線の放射線加重係数
#define W 66.8 //成人男性の体重
#define DD1MeV 3.03 //D-D反応1で発生する粒子の電子ボルト
#define DD2MeV 2.34 //D-D反応2で発生する粒子の電子ボルト
#define DTMeV 14 //D-T反応で発生する粒子の電子ボルト
#define D3HeMeV 14.7 ////D-3^He反応で発生する粒子の電子ボルト

typedef struct {
 double data[N];
 int top;
} stack;


typedef struct {
 double mass;
 int number;
} fusion;

typedef struct {
 double toe;
 double tnt;
 double lb;
 double aec;
} conv;


void initStack(stack* sp, int n);
double topValue(stack* sp);
void push(stack* sp, double v);
double pull(stack *sp);
void printStack(stack *stackp); 
void addStack(stack *stackp); 
void subStack(stack *stackp); 
void mulStack(stack *stackp); 
void divStack(stack *stackp);


fusion input();
double fusionEne(fusion myFusion);
conv conversion(double E);
void ALICE();
double sv(fusion myFusion);
void output(double E, conv myConv, double sv);


#endif
