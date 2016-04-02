#ifndef GLUT_TEST_THREAD_MAIN_
#define GLUT_TEST_THREAD_MAIN_
#endif

#ifdef GLUT_TEST_THREAD_MAIN_

#include <thread>
#include <mutex>

int v;

int plusplus(int *x)
{
	return (*x)++;
}

class TestThread
{
public:
	TestThread(int& value){value_ = value; value *= -1; }
	void operator() () const
	{
		for (int i = 0; i < 10; i++)
		{
			//*value_ *= -1;
			printf("I'm thread %d ...\n", value_);
		}
	}
	~TestThread(){}
private:
	int value_;
};

void test_ref(int& value_ref)
{
	value_ref *= -1;
	printf("in thread: %d\n", value_ref);
}

void main()
{
	int* values = new int[100];
	for (int i = 0; i < 100; i++)
	{
		values[i] = i;
	}
	//int v = 0;
	//for (int i = 0; i < 100; i++)
	//{
	//	TestThread t_i(values[i]);
	//	std::thread thread_i(t_i);
	//	thread_i.detach();
	//}

	//printf("main end.\n");

	//for (int i = 0; i < 100; i++)
	//{
	//	printf("%d\t", values[i]);
	//}

	std::thread ref_thread(&test_ref, /*std::ref*/(values[1]));
	ref_thread.detach();
	printf("%d\n", values[1]);

	system("pause");
}
#endif // GLUT_TEST_THREAD_MAIN_