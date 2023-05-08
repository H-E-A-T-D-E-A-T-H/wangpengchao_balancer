#include "PID.h"
double PID_angle_out(double angle_y)
{
	static double kp=9,kd=0.045,df,out,k=-3.5,last=1;
	df=(angle_y-k)-last;
	out=kp*(angle_y-k)+kd*df;
	last=angle_y-k;
//	if(out>200)
//		out=200;
//	else if(out<-200)
//		out=-200;
	return out;
}
double PID_speed_out(int EA,int EB,double target_speed)
{
	static double out,kp=1.7,ki,p,sum,p_speed_last=0,i=0;
	ki=kp/200;
	sum=(short)EA+(short)EB;
	p=sum-target_speed;
	i=p*0.7+p_speed_last*0.3;
	if(i>10000)
		i=10000;
	else if(i<-10000)
		i=-10000;
	p_speed_last=p;
	out=kp*p+ki*i;
//	if(out>200)
//		out=200;
//	else if(out<-200)
//		out=-200;
	return out;
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
