#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void convolution(float *p_Data,float *p_Filter, float*p_Output,int data_Long,int filter_Long);

int main()
{
    int i = 0;
    int data_Long = 10;
    int filter_Long = 3;
    float *p_Output = NULL;
    
    //int L_bior68 = 0;

    //float bior68_Lo[18]={0,0.0019,-0.0019,-0.0170,0.0119,0.0497,-0.0773,
                         // -0.0941,0.4208,0.8259,0.4208,-0.0941,-0.0773,
                          //0.0497,0.0119,-0.0170,-0.0019,0.0019};
    
    float data[10] = {0,1,2,3,4,5,6,7,8,9};
    float filter[3] = {1,2,1};
    float *p_Data;
    float *p_Filter;
    p_Data = data;
    p_Filter = filter;


            //    0,1,2,3,4,5,6,7,8,9,
            //    0,1,2,3,4,5,6,7,8,9,
            //    0,1,2,3,4,5,6,7,8,9,
            //    0,1,2,3,4,5,6,7,8,9};

    p_Output = new float[data_Long + filter_Long - 1];
    
    convolution (p_Data,p_Filter,p_Output,data_Long,filter_Long);

    

//测试延拓效果
    for( i = 0; i < data_Long + filter_Long - 1; i++)
    {


        printf("%f\n",*p_Output++);
        
    }

//    delete[] p_Output;


    return 0;
}


//函数申明
/*****************************************************************
      函数名：convolution
      函数功能：对输入向量进行滤波卷积
      函数参数：float *p_Data  ---指向输入向量指针
                float *p_filter ---指向滤波器向量指针
                float*p_output ---指向输出向量指针
                int data_Long    ---输入向量长度
                int filter_Long  ---滤波器长度
                
      程序默认data_Long > filter_Long            
      函数返回值：无
*****************************************************************/


void convolution(float *p_Data,float *p_Filter, float*p_Output,int data_Long,int filter_Long)
{
    int i = 0,j = 0;
    float temp = 0;

    for(i = 0;i < filter_Long;i++)
    {
        temp = 0;
        for(j = 0;j <= i;j++)
        {
            temp += *(p_Data + j) * (*(p_Filter + i - j));
            *(p_Output+i)  = temp;

        }
    }

    
    for(i = filter_Long;i < data_Long;i++)
    {
        temp = 0;
        for(j = 0;j < filter_Long;j++)
        {
            temp += *(p_Data + i -j) * (*(p_Filter + j));
            *(p_Output+i)  = temp;
        //    printf("%f\n",*(p_Output + i));
        }
    }

    
    for(i = data_Long;i < data_Long + filter_Long -1;i++)
    {
        temp = 0;
        for(j = i - data_Long + 1;j < filter_Long;j++)
        {
            temp += *(p_Data + i -j) * (*(p_Filter + j));
            *(p_Output+i)  = temp;

        }
    }
    
}
/////////////////////////////////////////////////////////////////////////
