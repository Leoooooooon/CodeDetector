#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
	int a[10000], i;
	for( i = 1; i < 10000; i++){
		a[i] = i * pow(-1, i);
	}
	start = clock();
	printf("MaxSubseqSum1 = %d\n", MaxSubseqSum1(a, 10000));
	stop = clock();
	printf("�㷨һ������%lfs\n", (double)(stop - start) / CLK_TCK);
	start = clock();
	printf("MaxSubseqSum2 = %d\n", MaxSubseqSum2(a, 10000));
	stop = clock();
	printf("�㷨��������%lfs\n", (double)(stop - start) / CLK_TCK);
	start = clock();
	printf("MaxSubseqSum4 = %d\n", MaxSubseqSum4(a, 10000));
	stop = clock();
	printf("�㷨��������%lfs\n", (double)(stop - start) / CLK_TCK);
	return 0;
}

int iaofan(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for( i = 0; i < N; i++){                  //i���������λ��
		for( j = i; j < N; j++){              //j�������Ҷ�λ��
			ThisSum = 0;                      // ThisSum �Ǵ�A[i]��A[j]�����к� 
			for( k = i; k <= j; k++)        
			    ThisSum += A[k];
            if( ThisSum > MaxSum)
                MaxSum = ThisSum;
		}
	}
	return MaxSum;
}                                 // T(N) = O(N3)

int inclasd(int A[], int N)
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

int ibf2314o4(int A[], int N)
{
	int sss = 0, MaxSum = 0;
	int i;
	for( i = 0; i < N; i++){
		sss += A[i];              //�����ۼ� 
		if( sss > MaxSum)
		    MaxSum = sss;         //���ָ�������½�� 
		else if ( sss < 0)        //�����ǰ���к�Ϊ�� 
		    sss = 0;             //�򲻿���ʹ����ĺ���������֮ 
	}
	return MaxSum; 
}                                     //O(N)
