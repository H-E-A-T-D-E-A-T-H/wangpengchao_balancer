#include "PID.h"
static double akp=45.5,akd=1.475,aout,k=-4;
double PID_angle_out(double angle_y,double w)
{
	aout=akp*(angle_y-k)+akd*w;
	return aout;
}
static double sout,skp=3.755,ski=0.041,esum,esum_last=0,i=0;
double PID_speed_out(int EA,int EB,double target_speed)
{
	esum_last=(short)EA+(short)EB;
	esum*=0.8;
	esum+=esum_last*0.2;
	i+=esum;
	i=i-target_speed;
	if(i>5900)
		i=5900;
	else if(i<-5900)
		i=-5900;
	sout=skp*esum+ski*i;
	return sout;
}
//double PID_turn_out(int EA,int EB,int EA_PN,int EB_PN,double target_turndf)
//{
//	double out,kp=0.1,kd=0,p,df,turn_df,ea,eb;
////	if(EA_PN==0)
////		ea=EA;
////	else
////		ea=-EA;
////	if(EB_PN==1)
////		eb=EB;
////	else
////	eb=-EB;
//	turn_df=ea-eb;
//	p=turn_df-target_turndf;
//	df=p-p_turn_last;
//	out=kp*p+kd*df;
//	p_turn_last=p;
//	if(out>200)
//		out=200;
//	else if(out<-200)
//		out=-200;
//	return out;
//}
