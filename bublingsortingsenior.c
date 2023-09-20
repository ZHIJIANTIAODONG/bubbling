//使用回调函数创建冒泡排序
//要求可以比较各种类型，通用
//多线程编程，中间人
//函数指针数组int (*pa[5])(int,int)  --转移表
//指向函数指针数组的指针int (*(*par)[5])(int,int) =&pa
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
void bubble_sort (int arr[],int sz)//普通的冒泡排序
{
    int i=0;
    for(i=0;i<sz-1;i++)
    {
        int j=0;
        for(j=0;j<sz-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
            int tmp=arr[j];
            arr[j] = arr[j+1];
            arr[j+1]=tmp;
            }
        }
    }
}

struct Stu
{
    char name[20];
    int age;
};

//void qsort(void *base,size_t num,size_t width,int( *compare)(const void *elem1,const void *elem2));
//函数原型
int cmp_int(const void* e1,const void* e2)
{
    //比较两个整型值
    return *(int*)e1 - *(int*)e2;
}

void test1()
{
    int arr[10] = {1,7,8,6,5,4,2,3,0,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    int i=0;
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
}

int cmp_float(const void*e1,const void*e2)
{
    if (*(float*)e1 = *(float*)e2)
        return 0;
        else if(*(float*)e1 > *(float*)e2)
        return 1;
        else
        return -1;
    //return (int)(*(float*)e1-*(float*)e2)
}

void test2()
{
    float f[]={9.1,8.0,7.0,6.0,5.0,4.0};
    int sz=sizeof(f)/sizeof(f[0]);
    qsort(f,sz,sizeof(f[0]),cmp_float);
    int i=0;
    for(i=0;i<sz;i++)
    {
        printf("%f ",f[i]);
    }
}

int cmp_stu_by_age(const void*e1,const void*e2)
{
    return  ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void*e1,const void*e2)
{
    //比较字符串，不能直接大于小于，应该用strcmp函数
    return strcmp(((struct Stu*)e1)->name  , ((struct Stu*)e2)->name) ;
}

void test3()
{
    struct Stu s[3] ={{"zhangsan",20},{"lisi",30},{"wangwu",10}};
    int sz = sizeof(s)/sizeof(s[0]);
    qsort(s,sz,sizeof(s[0]),cmp_stu_by_name);
    //第一个参数，待排序数组的首元素地址
    //第二个参数，待排序元素个数
    //第三个参数，待排序数组的每个元素的大小-字节
    //第四个参数，函数指针，比较两个元素所用的函数地址，这个函数使用者自己实现，函数指针的两个参数是：待比较的两个元素的地址
}
int main()
{
    //struct Stu s[3] ={{"zhangsan",20},{"lisi",30},{"wangwu",10}};
    //test1();
    //test2();
    test3();
    //bubble_sort(arr,sz);
    return 0;
}







