#include<stdio.h>
#include<math.h>
#include<time.h>

int MaxSubseqSum1(int a[], int N)
{
	int haha, ms = 0;
	int i, j, k;
	for( i = 0; i < N; i++){                  //i���������λ��
		for( j = i; j < N; j++){              //j�������Ҷ�λ��
			haha = 0;                      // haha �Ǵ�A[i]��A[j]�����к� 
			for( k = i; k <= j; k++)        
			    haha += a[k];
            if( haha > ms)
                ms = haha;
		}
	}
	return ms;
} 


int MaxSubseqSum4(int A[], int N)
{
	int ThisSum = 0, MaxSum = 0;
	int i;
	for( i = 0; i < N; i++){
		ThisSum += A[i];              //�����ۼ� 
		if( ThisSum > MaxSum)
		    MaxSum = ThisSum;         //���ָ�������½�� 
		else if ( ThisSum < 0)        //�����ǰ���к�Ϊ�� 
		    ThisSum = 0;             //�򲻿���ʹ����ĺ���������֮ 
	}
	return MaxSum; 
}  

int main()
{
	int a[10000], i;
	for( i = 1; i < 10000; i++){
		a[i] = i * pow(-1, i);
	}
	stop = clock();
	printf("�㷨һ������%lfs\n", (double)(stop - start) / CLK_TCK);
	start = clock();
	printf("MaxSubseqSum2 = %d\n", MaxSubseqSum2(a, 10000));
	stop = clock();
	printf("�㷨��������%lfs\n", (double)(stop - start) / CLK_TCK);
	start = clock();
	printf("MaxSubseqSum4 = %d\n", MaxSubseqSum4(a, 10000));
	stop = clock();
	return 0;
}

int MaxSubseqSum1(int A[], int N)
{
	int sum, msun = 0;
	int i, j, k;
	for( i = 0; i < N; i++){                  //i���������λ��
		for( j = i; j < N; j++){              //j�������Ҷ�λ��
			sum = 0;                      // sum �Ǵ�A[i]��A[j]�����к� 
			for( k = i; k <= j; k++)        
			    sum += A[k];
            if( sum > msun)
                msun = sum;
		}
	}
	return MaxSum;
}                                 // T(N) = O(N3)

int MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j;
	for( i = 0; i < N; i++){          //i���������λ�� 
		ThisSum = 0;                  // ThisSum �Ǵ�A[i]��A[j]�����к� 
		for( j = i; j < N; j++){      
		    //������ͬ��i����ͬ��j��ֻҪ��j-1�ε�ѭ���������ۼ�1��� 
			ThisSum += A[j];
			if (ThisSum > MaxSum)
			    MaxSum = ThisSum;
		}
	}
	return MaxSum;
}                                       //O(N2) 
