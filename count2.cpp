#include <iostream>
#include <cmath>

void show(int *LS ,int n)
{
	for(int i=0; i<n*n; i++)
	{
		if(i%n==0)
		{
		std::cout <<  std::endl;	
		}
		if(LS[i]==-1)
		{
			std::cout << " 1";	
		}
		else
		{
			std::cout << " "<< LS[i]; 
		}
	}
	std::cout <<  std::endl;
}

int findvalue(int *LS , int M, int N, int min, int i)
{
	int n2=M*M*N*N;
	int n=M*N;
	int set[20];
	for(int j=0; j<n; j++)
	{
		if(j+1>min)
		{
			set[j]=j+1;
		}
		else
		{
			set[j]=0;
		}
	}
	int row=i/n;
	for(int k=0; k<n; k++)
	{
			set[LS[row*n+k]-1]=0;
	}

	int column=i % n;
	for(int k=0; k<n; k++)
	{
		set[LS[k*n+column]-1]=0;
	}
	
	int a1=(i % n)/M;
	int a3=i/(n*N);
	//std::cout << "a1 "<< a1 << std::endl;
	//std::cout << "a2 "<< a3 << std::endl;
	
	for(int k=0; k<M; k++)
	{
		for(int j=0; j<N; j++)
		{
			set[LS[a3*n*N+a1*M+k+j*N*M]-1]=0;
		}
	}
	
	for(int k=0; k<n; k++)
	{
		if(set[k]!=0)
		{
			return k+1;
		}
	}
	return 0;
}

int backtrackingcheck(int *LS , int M, int N)
{
	int n2=M*M*N*N;
	int *kopib;
	int count=0;
	// laver en kopi
	std::cout << "A1" << std::endl;
	kopib= new int[n2];
	for(int j=0; j<n2; j++)
	{
		kopib[j]=LS[j];
	}	


	for(int i=0; i<n2; i++)
	{
		if(kopib[i]==0)
		{
			//std::cout << "i "<< i << std::endl;
			kopib[i]=findvalue(kopib,M,N,kopib[i],i);
		}
		while(kopib[i]==0)
		{

			//std::cout << i <<  std::endl;
			i--;
			while(LS[i]>0)
			{
				i--;
				if(i==-1)
				{
					std::cout <<  std::endl;
					std::cout << "NO SOLUTION" <<  std::endl;
					show(kopib,M*N);
					delete kopib;
					return 0;
				}
				
			}
			if(LS[i]==0)
			{
				kopib[i]=findvalue(kopib,M,N,kopib[i],i);	
			}

			if(i==-1)
			{
				std::cout <<  std::endl;
				std::cout << "NO SOLUTION" <<  std::endl;
				show(kopib,M*N);
				delete kopib;
				return 0;
			}
			
			
		}
	}
	std::cout << "A2" << std::endl;
	count++;
	show(kopib,M*N);

	//return 0;
	int go=n2-1;
	while(LS[go]>0)
	{
		go--;
	}
	std::cout << "A3" << std::endl;
	int i=go;
	while(1==1)
	{

		if(LS[i]==0)
		{
			kopib[i]=findvalue(kopib,M,N,kopib[i],i);
		}
		while(kopib[i]==0)
		{

			//std::cout << i <<  std::endl;
			i--;
			while(LS[i]>0)
			{
				i--;
				if(i==-1)
				{
					//std::cout <<  std::endl;
					//std::cout << "UNIQUE SOLUTION" <<  std::endl;
					delete kopib;
					return count;
				}
				
			}
			if(LS[i]==0)
			{
				kopib[i]=findvalue(kopib,M,N,kopib[i],i);	
			}

			if(i==-1)
			{
				//std::cout <<  std::endl;
				//std::cout << "UNIQUE SOLUTION" <<  std::endl;
				delete kopib;
				return count;
			}
		}
		i++;
		if(i>n2-1)
		{
			count++;
			if(count % 100000==0)
			{
				std::cout << count << std::endl;
			}
			i--;
		}
		
	}
}

void countsol(int M , int N)
{
	int *test;
	int n2=M*M*N*N;
	test= new int[n2];
	for(int i=0;i<n2;i++)
	{
		test[i]=0;
	}
	for(int i=0;i<M*N;i++)
	{
		test[i]=i+1;
	}
	std::cout << backtrackingcheck(test,M,N) <<  std::endl;
	
}

int main(int argc, char* argv[])
{

	//countsol(1,1);
	//countsol(1,2);
	countsol(2,2);
	countsol(2,3);
	//countsol(3,3);
	//countsol(1,3);
	//countsol(2,3);

	int test12[16];
	test12[0]=1;
	test12[1]=2;
	test12[2]=2;
	test12[3]=0;
	//std::cout << findvalue(test12,1,2,0,3) << std::endl;
	int i;
	std::cin >> i;	


}