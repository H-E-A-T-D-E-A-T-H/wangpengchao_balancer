#include "MPU6050.h"
#include "string.h"
float a[3],w[3],angle[3],T;
unsigned char Temp[11];

void MPU6050_Data(unsigned char Re_buf[11])
{
	memcpy(Temp,Re_buf,11);
	if(Re_buf[0]==0x55)       //���֡ͷ
	{
		switch(Re_buf[1])
		{
//			case 0x51: //��ʶ������Ǽ��ٶȰ�
//				a[0] = ((short)(Temp[3]<<8 | Temp[2]))/32768.0*16;      //X����ٶ�
//				a[1] = ((short)(Temp[5]<<8 | Temp[4]))/32768.0*16;      //Y����ٶ�
//				a[2] = ((short)(Temp[7]<<8 | Temp[6]))/32768.0*16;      //Z����ٶ�
//				T    = ((short)(Temp[9]<<8 | Temp[8]))/340.0+36.25;      //�¶�
//				break;
			case 0x52: //��ʶ������ǽ��ٶȰ�
				w[0] = ((short)(Temp[3]<<8| Temp[2]))/32768.0*2000;      //X����ٶ�
				w[1] = ((short)(Temp[5]<<8| Temp[4]))/32768.0*2000;      //Y����ٶ�
				w[2] = ((short)(Temp[7]<<8| Temp[6]))/32768.0*2000;      //Z����ٶ�
//				T    = ((short)(Temp[9]<<8| Temp[8]))/340.0+36.25;      //�¶�
				break;
			case 0x53: //��ʶ������ǽǶȰ�
				angle[0] = ((short)(Temp[3]<<8| Temp[2]))/32768.0*180;   //X���ת�ǣ�x �ᣩ
				angle[1] = ((short)(Temp[5]<<8| Temp[4]))/32768.0*180;   //Y�ḩ���ǣ�y �ᣩ
				angle[2] = ((short)(Temp[7]<<8| Temp[6]))/32768.0*180;   //Z��ƫ���ǣ�z �ᣩ
//				T        = ((short)(Temp[9]<<8| Temp[8]))/340.0+36.25;   //�¶�
				break;
			default:  break;
		}
	}
}
