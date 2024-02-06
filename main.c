/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

/*
  代码移动、减少函数调用、减少访存次数、分支预测、循环展开、并行处理、cache友好等。
*/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "bovik",              /* Team name */

    "Harry Q. Bovik",     /* First member full name */
    "bovik@nowhere.edu",  /* First member email address */

    "ZZQ",                   /* Second member full name (leave blank if none) */
    "323"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 * 朴素旋转 - 旋转的朴素基础版本
 * 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 * 这是用来打分的函数
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    naive_rotate(dim, src, dst);
}

char rotate_descr1[] = "rotate1: Current working version";
// 分块旨在提高空间局部性
void rotate1(int dim, pixel *src, pixel *dst) 
{
    int i,j,ki,kj;
    //分块，我这里分为8*8作为一块 
    for (i = 0; i < dim; i+=8) //每块8行
    for (j = 0; j < dim; j+=8) //每块8列
    for(ki=i; ki<i+8; ki++) for(kj=j; kj<j+8; kj++) 
        dst[RIDX(dim-1-kj, ki, dim)] = src[RIDX(ki, kj, dim)];
}

char rotate_descr2[] = "rotate2: Current working version";
void rotate2(int dim, pixel *src, pixel *dst) 
{
    int i,j,ki,kj;
    //分块+循环展开，这里32*32分块，4*4循环展开
    for (i = 0; i < dim; i+=32) //每块32行
    for (j = 0; j < dim; j+=32) //每块32列
    for(ki=i; ki<i+32; ki+=4) //控制循环展开的行
    for(kj=j; kj<j+32; kj+=4) {//控制循环展开的列
        //相当于在4*4的小块内，手写每一个像素点的旋转变换
        dst[RIDX(dim-1-kj, ki, dim)] = src[RIDX(ki, kj, dim)];
        dst[RIDX(dim-1-kj-1, ki, dim)] = src[RIDX(ki, kj+1, dim)];
        dst[RIDX(dim-1-kj-2, ki, dim)] = src[RIDX(ki, kj+2, dim)];
        dst[RIDX(dim-1-kj-3, ki, dim)] = src[RIDX(ki, kj+3, dim)];

        dst[RIDX(dim-1-kj, ki+1, dim)] = src[RIDX(ki+1, kj, dim)];
        dst[RIDX(dim-1-kj-1, ki+1, dim)] = src[RIDX(ki+1, kj+1, dim)];
        dst[RIDX(dim-1-kj-2, ki+1, dim)] = src[RIDX(ki+1, kj+2, dim)];
        dst[RIDX(dim-1-kj-3, ki+1, dim)] = src[RIDX(ki+1, kj+3, dim)];

        dst[RIDX(dim-1-kj, ki+2, dim)] = src[RIDX(ki+2, kj, dim)];
        dst[RIDX(dim-1-kj-1, ki+2, dim)] = src[RIDX(ki+2, kj+1, dim)];
        dst[RIDX(dim-1-kj-2, ki+2, dim)] = src[RIDX(ki+2, kj+2, dim)];
        dst[RIDX(dim-1-kj-3, ki+2, dim)] = src[RIDX(ki+2, kj+3, dim)];

        dst[RIDX(dim-1-kj, ki+3, dim)] = src[RIDX(ki+3, kj, dim)];
        dst[RIDX(dim-1-kj-1, ki+3, dim)] = src[RIDX(ki+3, kj+1, dim)];
        dst[RIDX(dim-1-kj-2, ki+3, dim)] = src[RIDX(ki+3, kj+2, dim)];
        dst[RIDX(dim-1-kj-3, ki+3, dim)] = src[RIDX(ki+3, kj+3, dim)];		
    }
}

char rotate_descr3[] = "rotate3: Current working version";
void rotate3(int dim, pixel *src, pixel *dst) 
{
    int i,j;
    //分块+循环展开+改变顺序
    for (i = 0; i < dim; i+=16)for (j = 0; j < dim; j++) 
    {
        //在这里不再以行优先，而是每32行为一块，列优先
        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
        dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
        dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
        dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
        dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
        dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
        dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
        dst[RIDX(dim-1-j, i+8, dim)] = src[RIDX(i+8, j, dim)];
        dst[RIDX(dim-1-j, i+9, dim)] = src[RIDX(i+9, j, dim)];
        dst[RIDX(dim-1-j, i+10, dim)] = src[RIDX(i+10, j, dim)];
        dst[RIDX(dim-1-j, i+11, dim)] = src[RIDX(i+11, j, dim)];
        dst[RIDX(dim-1-j, i+12, dim)] = src[RIDX(i+12, j, dim)];
        dst[RIDX(dim-1-j, i+13, dim)] = src[RIDX(i+13, j, dim)];
        dst[RIDX(dim-1-j, i+14, dim)] = src[RIDX(i+14, j, dim)];
        dst[RIDX(dim-1-j, i+15, dim)] = src[RIDX(i+15, j, dim)];
    }
}

// typedef struct{
//     unsigned short red;
//     unsigned short green;
//     unsigned short blue;
//     unsigned short waste;
// }pixel;

// char rotate_descr4[] = "rotate4: Current working version";
// void rotate4(int dim, pixel *src, pixel *dst) 
// {
//     for (i = 0; i < dim; i+=32)
// 	for (j = 0; j < dim; j++)
// 		for(k=0; k<32; k++) {
// 			dst[RIDX(dim-1-j, i+k, dim)].red = src[RIDX(i+k, j, dim)].red;
// 			dst[RIDX(dim-1-j, i+k, dim)].green = src[RIDX(i+k, j, dim)].green;
// 			dst[RIDX(dim-1-j, i+k, dim)].blue = src[RIDX(i+k, j, dim)].blue;
// 	}
// }

char rotate_descr5[] = "rotate5: Current working version";
void rotate5(int dim, pixel *src, pixel *dst) 
{
    int i,j,k;
    for (i = 0; i < dim; i+=32)for (j = 0; j < dim; j++)
    for(k=0; k<32; k++) 
        dst[(dim-1-j)*dim+i+k] = src[(i+k)*dim+j];
}

char rotate_descr6[] = "rotate6: Current working version";
void rotate6(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    //src初始化为第一行第一个像素点，dst与之对应，应指向最后一行第一个像素点
    dst += (dim-1)*dim;
    for (i = 0; i < dim; i+=32)
    { 
        for (j = 0; j < dim; j++)
        { 
            //循环展开，共32：
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src; src+=dim; dst+=1;
            *dst=*src;
            //注意修改src与dst指向的位置，改为下一列的相应32行
            src++;
            src-= (dim<<5)-dim; 
            dst-=31+dim;
        }
        dst+=dim*dim;
        dst+=32;
        src += (dim<<5)-dim;
    }
}





/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 * 注册所有不同版本旋转函数；
 * 注册是为了在测试的时候一一测试你写好的函数
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value
   * 
   * red、green、blue分别代表RGB的数值
   * 
   * num是数值？
   * 
*/
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static inline int min(int a, int b) { return (a < b ? a : b); }
static inline int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 * 
 * 在sum里面累加p的RGB、还有num累加次数
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 * 将sum的所有数值，除以周围给他赋值的点数，相当于是分别算一个RGB的均值
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 * 返回在(i,j)处的像素的平均值
 * dim - 维度
 * i，j 是坐标
 * src是整个图像
 * 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
    for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 * smooth 的朴素基础版本
 * dim是整个像素数组的边长大小（长和宽），虽然他只是一个一维数组
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 * 这是用来给你打分的smooth函数
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    naive_smooth(dim, src, dst);
}

char smooth_descr1[] = "smooth1: Current working version";

void smooth1(int dim, pixel *src, pixel *dst) 
{
	// 消除过多的函数调用，独立计算不同位置的像素点，
    // 将所有除法运算由除变量改为除常量
	int i=1,j=0;
	//处理左上角顶点
	dst[0].red=(src[0].red+src[1].red+src[dim].red+src[dim+1].red)/4;
	dst[0].green=(src[0].green+src[1].green+src[dim].green+src[dim+1].green)/4;
	dst[0].blue=(src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)/4;
	//处理第一行其他非右上角顶点
	for(j=1; j<dim-1; j++) {
		dst[j].red=(src[j-1].red+src[j].red+src[j+1].red+src[dim+j-1].red+src[dim+j].red+src[dim+j+1].red)/6;
		dst[j].green=(src[j-1].green+src[j].green+src[j+1].green+src[dim+j-1].green+src[dim+j].green+src[dim+j+1].green)/6;
		dst[j].blue=(src[j-1].blue+src[j].blue+src[j+1].blue+src[dim+j-1].blue+src[dim+j].blue+src[dim+j+1].blue)/6;
	}
	//处理右上角顶点
	dst[j].red=(src[j].red+src[j-1].red+src[dim+j].red+src[dim+j-1].red)/4;
	dst[j].green=(src[j].green+src[j-1].green+src[dim+j].green+src[dim+j-1].green)/4;
	dst[j].blue=(src[j].blue+src[j-1].blue+src[dim+j].blue+src[dim+j-1].blue)/4;
	//处理1至dim-2行
	for(; i<dim-1; i++) {
		//处理每一行的第一个像素点
		dst[i*dim].red=(src[(i-1)*dim].red+src[(i-1)*dim+1].red+src[i*dim].red+src[i*dim+1].red+src[(i+1)*dim].red+src[(i+1)*dim+1].red)/6;
		dst[i*dim].green=(src[(i-1)*dim].green+src[(i-1)*dim+1].green+src[i*dim].green+src[i*dim+1].green+src[(i+1)*dim].green+src[(i+1)*dim+1].green)/6;
		dst[i*dim].blue=(src[(i-1)*dim].blue+src[(i-1)*dim+1].blue+src[i*dim].blue+src[i*dim+1].blue+src[(i+1)*dim].blue+src[(i+1)*dim+1].blue)/6;
		//处理每一行第二个至第dim-1个像素点
		for(j=1; j<dim-1; j++) {
			dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[(i-1)*dim+j+1].red+src[i*dim+j-1].red+src[i*dim+j].red+src[i*dim+j+1].red+src[(i+1)*dim+j-1].red+src[(i+1)*dim+j].red+src[(i+1)*dim+j+1].red)/9;
			dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[(i-1)*dim+j+1].green+src[i*dim+j-1].green+src[i*dim+j].green+src[i*dim+j+1].green+src[(i+1)*dim+j-1].green+src[(i+1)*dim+j].green+src[(i+1)*dim+j+1].green)/9;
			dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[(i-1)*dim+j+1].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[i*dim+j+1].blue+src[(i+1)*dim+j-1].blue+src[(i+1)*dim+j].blue+src[(i+1)*dim+j+1].blue)/9;
		}
		//处理每一行最后一个像素点
		dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[i*dim+j-1].red+src[i*dim+j].red+src[(i+1)*dim+j-1].red+src[(i+1)*dim+j].red)/6;
		dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[i*dim+j-1].green+src[i*dim+j].green+src[(i+1)*dim+j-1].green+src[(i+1)*dim+j].green)/6;
		dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[(i+1)*dim+j-1].blue+src[(i+1)*dim+j].blue)/6;
	}
	//处理左下角像素点
	dst[i*dim].red=(src[(i-1)*dim].red+src[(i-1)*dim+1].red+src[i*dim].red+src[i*dim+1].red)/4;
	dst[i*dim].green=(src[(i-1)*dim].green+src[(i-1)*dim+1].green+src[i*dim].green+src[i*dim+1].green)/4;
	dst[i*dim].blue=(src[(i-1)*dim].blue+src[(i-1)*dim+1].blue+src[i*dim].blue+src[i*dim+1].blue)/4;
	//处理最后一行非左下角、非右下角的像素点
	for(j=1; j<dim-1; j++) {
		dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[(i-1)*dim+j+1].red+src[i*dim+j-1].red+src[i*dim+j].red+src[i*dim+j+1].red)/6;
		dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[(i-1)*dim+j+1].green+src[i*dim+j-1].green+src[i*dim+j].green+src[i*dim+j+1].green)/6;
		dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[(i-1)*dim+j+1].blue+src[i*dim+j-1].blue+src[i*dim+j].blue+src[i*dim+j+1].blue)/6;
	}
	//处理右下角像素点
	dst[i*dim+j].red=(src[(i-1)*dim+j-1].red+src[(i-1)*dim+j].red+src[i*dim+j-1].red+src[i*dim+j].red)/4;
	dst[i*dim+j].green=(src[(i-1)*dim+j-1].green+src[(i-1)*dim+j].green+src[i*dim+j-1].green+src[i*dim+j].green)/4;
	dst[i*dim+j].blue=(src[(i-1)*dim+j-1].blue+src[(i-1)*dim+j].blue+src[i*dim+j-1].blue+src[i*dim+j].blue)/4;	
}

// 程序运行过程中比较多的重复计算量
// 将每一个像素点的计算转换为一个块(2x2或2x3或3x2或3x3)内的各个像素点取平均值，
// 并将每一块纵向分开为2或3个纵向块，用动规数组记录每一列(2个或3个像素点)的R、G、B之和。
// 相邻的两个纵向块之间存在递推关系
// 递推关系为纵向，因此读运算的空间局部性较差，产生了大量的不命中
// 可以将递推关系改为横向
char smooth_descr2[] = "smooth2: Current working version";
void smooth2(int dim, pixel *src, pixel *dst) 
{
	//使用数组存储中间结果，纵向的DP优化
	int i,j;
	int r2[2][dim],g2[2][dim],b2[2][dim];//从上到下2个
	int r3[dim][dim],g3[dim][dim],b3[dim][dim];//从上到下3个
	for(j=0; j<dim; j++) {
		// 第j列一开始的大小为2的子块
        // 这里的子块是竖直的长方形
		r2[0][j]=src[j].red;
		g2[0][j]=src[j].green;
		b2[0][j]=src[j].blue;
		r2[0][j]+=src[dim+j].red;
		g2[0][j]+=src[dim+j].green;
		b2[0][j]+=src[dim+j].blue;
		//第j列一开始的大小为3的子块
		r3[0][j]=r2[0][j]+src[(dim<<1)+j].red;
		g3[0][j]=g2[0][j]+src[(dim<<1)+j].green;
		b3[0][j]=b2[0][j]+src[(dim<<1)+j].blue;
		//递推得到其他子块
		for(i=1; i<dim-2; i++) {
            // src[(i-1)*dim+j] --> src[(i-1)*dim][j]
			r3[i][j]=r3[i-1][j]-src[(i-1)*dim+j].red+src[(i+2)*dim+j].red;
			g3[i][j]=g3[i-1][j]-src[(i-1)*dim+j].green+src[(i+2)*dim+j].green;
			b3[i][j]=b3[i-1][j]-src[(i-1)*dim+j].blue+src[(i+2)*dim+j].blue;
		}
		//最后一个长度为2的子块
		r2[1][j]=r3[dim-3][j]-src[(dim-3)*dim+j].red;
		g2[1][j]=g3[dim-3][j]-src[(dim-3)*dim+j].green;
		b2[1][j]=b3[dim-3][j]-src[(dim-3)*dim+j].blue;
	}
	//处理左上角顶点
	dst[0].red=(r2[0][0]+r2[0][1])/4;
	dst[0].green=(g2[0][0]+g2[0][1])/4;
	dst[0].blue=(b2[0][0]+b2[0][1])/4;
	//处理第一行其他非右上角顶点
	for(j=1; j<dim-1; j++) {
		dst[j].red=(r2[0][j-1]+r2[0][j]+r2[0][j+1])/6;
		dst[j].green=(g2[0][j-1]+g2[0][j]+g2[0][j+1])/6;
		dst[j].blue=(b2[0][j-1]+b2[0][j]+b2[0][j+1])/6;
	}
	//处理右上角顶点
	dst[j].red=(r2[0][j-1]+r2[0][j])/4;
	dst[j].green=(g2[0][j-1]+g2[0][j])/4;
	dst[j].blue=(b2[0][j-1]+b2[0][j])/4;
	//处理1至dim-2行
	for(i=1; i<dim-1; i++) {
		//处理每一行的第一个像素点 dst[i*dim] -- dst[i][0]
		dst[i*dim].red=(r3[i-1][0]+r3[i-1][1])/6;
		dst[i*dim].green=(g3[i-1][0]+g3[i-1][1])/6;
		dst[i*dim].blue=(b3[i-1][0]+b3[i-1][1])/6;
		//处理每一行第二个至第dim-1个像素点
		for(j=1; j<dim-1; j++) {
			dst[i*dim+j].red=(r3[i-1][j-1]+r3[i-1][j]+r3[i-1][j+1])/9;
			dst[i*dim+j].green=(g3[i-1][j-1]+g3[i-1][j]+g3[i-1][j+1])/9;
			dst[i*dim+j].blue=(b3[i-1][j-1]+b3[i-1][j]+b3[i-1][j+1])/9;
		}
		//处理每一行最后一个像素点
		dst[i*dim+j].red=(r3[i-1][j-1]+r3[i-1][j])/6;
		dst[i*dim+j].green=(g3[i-1][j-1]+g3[i-1][j])/6;
		dst[i*dim+j].blue=(b3[i-1][j-1]+b3[i-1][j])/6;
	}
	//处理左下角像素点
	dst[i*dim].red=(r2[1][0]+r2[1][1])/4;
	dst[i*dim].green=(g2[1][0]+g2[1][1])/4;
	dst[i*dim].blue=(b2[1][0]+b2[1][1])/4;
	//处理最后一行非左下角、非右下角的像素点
	for(j=1; j<dim-1; j++) {
		dst[i*dim+j].red=(r2[1][j-1]+r2[1][j]+r2[1][j+1])/6;
		dst[i*dim+j].green=(g2[1][j-1]+g2[1][j]+g2[1][j+1])/6;
		dst[i*dim+j].blue=(b2[1][j-1]+b2[1][j]+b2[1][j+1])/6;	
	}
	//处理右下角像素点
	dst[i*dim+j].red=(r2[1][j-1]+r2[1][j])/4;
	dst[i*dim+j].green=(g2[1][j-1]+g2[1][j])/4;
	dst[i*dim+j].blue=(b2[1][j-1]+b2[1][j])/4;	
}

// 因为行优先读写，所以平行扫着处理
// 每个指针控制行相邻的两个或三个像素点的读运算
char smooth_descr3[] = "smooth3: Current working version";
void smooth3(int dim, pixel *src, pixel *dst) 
{
	//使用指针，尽量少移动
    int i,j;
	//每一个指针对应一行
    pixel *pixelA,*pixelB,*pixelC;
    int size = dim-1;
    //处理第一行第一个像素点
    pixelB = src;
    pixelC = pixelB + dim;
    dst->red = (pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)>>2;
    dst->green = (pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)>>2;
    dst->blue = (pixelB->blue + (pixelB+1)->blue + pixelC->blue + (pixelC+1)->blue)>>2;
    pixelB++;
    pixelC++;
    dst++;
    //处理第一行中间的dim-2个像素点
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/6;
        dst->green = (pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/6;
        dst->blue = (pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/6;
        pixelB++;
        pixelC++;
        dst++;
    }
    //处理第一行最后一个像素点
    dst->red = (pixelC->red + (pixelC-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelC->green + (pixelC-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelC->blue + (pixelC-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
    dst++;
	//开始处理中间的dim-2行
    pixelA = src;
    pixelB = pixelA + dim;
    pixelC = pixelB + dim;
    for(i = 1; i < size; i++)
    {
        //对于每一行的第一个像素点
        dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red + pixelC->red + (pixelC+1)->red)/6;
        dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green + pixelC->green + (pixelC+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue + pixelC->blue+ (pixelC+1)->blue)/6;
        dst++;
        pixelA++;
        pixelB++;
        pixelC++;
        //对于每一行中间的dim-2个像素点
        for(j = 1; j < dim-1; j++)
        {
            dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red + pixelC->red + (pixelC-1)->red + (pixelC+1)->red)/9;
            dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green + pixelC->green + (pixelC-1)->green + (pixelC+1)->green)/9;
            dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue + pixelC->blue + (pixelC-1)->blue + (pixelC+1)->blue)/9;
            pixelA++;
            pixelB++;
            pixelC++;
            dst++;
        }
        //对于每一行最后一个像素点
        dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red + pixelC->red + (pixelC-1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green + pixelC->green + (pixelC-1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue + pixelC->blue+ (pixelC-1)->blue)/6;
        pixelA++;
        pixelB++;
        pixelC++;
        dst++;
    }
    //处理最后一行第一个像素点
    dst->red = (pixelA->red + (pixelA+1)->red + pixelB->red + (pixelB+1)->red)>>2;
    dst->green = (pixelA->green + (pixelA+1)->green + pixelB->green + (pixelB+1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA+1)->blue + pixelB->blue + (pixelB+1)->blue)>>2;
    dst++;
    pixelA++;
    pixelB++;
    //处理最后一行中间dim-2个像素点
    for(i = 1; i < size; i++)
    {
        dst->red = (pixelA->red + (pixelA-1)->red + (pixelA+1)->red + pixelB->red + (pixelB-1)->red + (pixelB+1)->red)/6;
        dst->green = (pixelA->green + (pixelA-1)->green + (pixelA+1)->green + pixelB->green + (pixelB-1)->green + (pixelB+1)->green)/6;
        dst->blue = (pixelA->blue + (pixelA-1)->blue + (pixelA+1)->blue + pixelB->blue + (pixelB-1)->blue + (pixelB+1)->blue)/6;
        pixelA++;
        pixelB++;
        dst++;
    }
    //处理最后一行最后一个像素点
    dst->red = (pixelA->red + (pixelA-1)->red + pixelB->red + (pixelB-1)->red)>>2;
    dst->green = (pixelA->green + (pixelA-1)->green + pixelB->green + (pixelB-1)->green)>>2;
    dst->blue = (pixelA->blue + (pixelA-1)->blue + pixelB->blue + (pixelB-1)->blue)>>2;
}


char smooth_descr4[] = "smooth4: Current working version";
void smooth4(int dim, pixel *src, pixel *dst) 
{
	int i,j,dest;
	//首先处理四个顶点
	//左上角顶点
	dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)>>2;
	dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)>>2;
	dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)>>2;
	//右上角顶点
	i=dim-1;
	j=dim*2-1;
	dst[i].red = (src[i].red+src[i-1].red+src[j].red+src[j-1].red)>>2;
	dst[i].blue = (src[i].blue+src[i-1].blue+src[j].blue+src[j-1].blue)>>2;
	dst[i].green = (src[i].green+src[i-1].green+src[j].green+src[j-1].green)>>2;
	//左下角顶点
	i=dim*(dim-1);
	j=dim*(dim-2);
	dst[i].red = (src[i].red+src[i+1].red+src[j].red+src[j+1].red)>>2;
	dst[i].blue = (src[i].blue+src[i+1].blue+src[j].blue+src[j+1].blue)>>2;
	dst[i].green = (src[i].green+src[i+1].green+src[j].green+src[j+1].green)>>2;
	//右下角顶点
	i=dim*dim-1;
	j=dim*(dim-1)-1;
	dst[i].red = (src[i].red+src[i-1].red+src[j].red+src[j-1].red)>>2;
	dst[i].blue = (src[i].blue+src[i-1].blue+src[j].blue+src[j-1].blue)>>2;
	dst[i].green = (src[i].green+src[i-1].green+src[j].green+src[j-1].green)>>2;
	//接下来处理四条边

	//上边
	dest = dim-1;
	i=dim+1;
  for (j = 1; j < dest; j++) {
    dst[j].red = (src[j-1].red+src[j].red+src[j+1].red+src[i-1].red+src[i].red+src[i+1].red)/6;
    dst[j].green = (src[j-1].green+src[j].green+src[j+1].green+src[i-1].green+src[i].green+src[i+1].green)/6;
    dst[j].blue = (src[j-1].blue+src[j].blue+src[j+1].blue+src[i-1].blue+src[i].blue+src[i+1].blue)/6;
    i++;
  }
	//下边
	dest = dim*dim-1;
	for (j = dim*(dim-1)+1; j < dest; j++) {
		i=j-dim;
		dst[j].red = (src[j-1].red+src[j].red+src[j+1].red+src[i-1].red+src[i].red
		              +src[i+1].red)/6;
		dst[j].green = (src[j-1].green+src[j].green+src[j+1].green+src[i-1].green+src[i].green
		                +src[i+1].green)/6;
		dst[j].blue = (src[j-1].blue+src[j].blue+src[j+1].blue+src[i-1].blue+src[i].blue
		               +src[i+1].blue)/6;
	}
	//左边
	dest = dim*dim-dim;
	for (j = dim; j < dest; j+=dim) {
		dst[j].red = (src[j].red+src[j+1].red+src[j-dim].red+src[j-dim+1].red+src[j+dim].red+src[j+1+dim].red)/6;
		dst[j].green = (src[j].green+src[j+1].green+src[j-dim].green+src[j-dim+1].green+src[j+dim].green+src[j+1+dim].green)/6;
		dst[j].blue = (src[j].blue+src[j+1].blue+src[j-dim].blue+src[j-dim+1].blue+src[j+dim].blue+src[j+1+dim].blue)/6;
	}
	//右边
	dest=dim*dim-1;
	for (j = dim+dim-1; j < dest; j+=dim) {
		dst[j].red = (src[j].red+src[j-1].red+src[j-dim].red+src[j-dim-1].red+src[j+dim].red+src[j-1+dim].red)/6;
		dst[j].green = (src[j].green+src[j-1].green+src[j-dim].green+src[j-1+dim].green+src[j+dim].green+src[j-dim-1].green)/6;
		dst[j].blue = (src[j].blue+src[j-1].blue+src[j-dim].blue+src[j-dim-1].blue+src[j+dim].blue+src[j-1+dim].blue)/6;
	}

	//处理中间的(dim-1)*(dim-1)个像素点
	pixel *pixelA = &src[0]; 
	pixel *pixelB = &src[dim];
	pixel *pixelC = &src[dim+dim];
	pixel *pixelD = &src[dim+dim+dim];

	//6个临时变量，存储3*2范围内的值
	int sum0_red, sum0_green, sum0_blue;
	int sum1_red, sum1_green, sum1_blue;
	int sum2_red, sum2_green, sum2_blue;
	int sum3_red, sum3_green, sum3_blue;
	int sum4_red, sum4_green, sum4_blue;
	int sum5_red, sum5_green, sum5_blue; 

	//index_为index的下面一个
	int index = dim+1;
	int index_ = index+dim;
	//对于1~dim-2行
	//循环展开:2，每次两行，index为本行，index_ 为下一行
	for (i = 1; i < dim - 2; i += 2) 
    {
		sum0_red = pixelB->red;
		sum0_blue = pixelB->blue;
		sum0_green = pixelB->green;

		sum0_red += pixelC->red;
		sum0_blue += pixelC->blue;
		sum0_green += pixelC->green;

		sum3_red = sum0_red+pixelD->red;
		sum3_green = sum0_green+pixelD->green;
		sum3_blue = sum0_blue+pixelD->blue;

		sum0_red += pixelA->red;
		sum0_blue += pixelA->blue;
		sum0_green += pixelA->green;
		//右移，此时sum0=A+B+C,sum3=B+C+D;
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		sum1_red = pixelB->red;
		sum1_blue = pixelB->blue;
		sum1_green = pixelB->green;

		sum1_red += pixelC->red;
		sum1_blue += pixelC->blue;
		sum1_green += pixelC->green;

		sum4_red = sum1_red+pixelD->red;
		sum4_green = sum1_green+pixelD->green;
		sum4_blue = sum1_blue+pixelD->blue;

		sum1_red += pixelA->red;
		sum1_blue += pixelA->blue;
		sum1_green += pixelA->green;
		//此时sum1=A+B+C,sum4=B+C+D;
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		sum2_red = pixelB->red;
		sum2_blue = pixelB->blue;
		sum2_green = pixelB->green;

		sum2_red += pixelC->red;
		sum2_blue += pixelC->blue;
		sum2_green += pixelC->green;

		sum5_red = sum2_red+pixelD->red;
		sum5_green = sum2_green+pixelD->green;
		sum5_blue = sum2_blue+pixelD->blue;

		sum2_red += pixelA->red;
		sum2_blue += pixelA->blue;
		sum2_green += pixelA->green;
		//此时sum2=A+B+C,sum5=B+C+D;
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
		dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
		dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
		index++;

		dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
		dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
		dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
		index_++;
		//右推
		sum0_red = sum1_red;
		sum1_red = sum2_red;
		sum0_green = sum1_green;
		sum1_green = sum2_green;
		sum0_blue = sum1_blue;
		sum1_blue = sum2_blue;

		sum3_red = sum4_red;
		sum4_red = sum5_red;
		sum3_green = sum4_green;
		sum4_green = sum5_green;
		sum3_blue = sum4_blue;
		sum4_blue = sum5_blue;
		
		//设置j<dim-4以防止越界，但有可能没处理完
		//循环展开:4，每一次：更新值+指针右移+赋值+临时变量右推
		for (j = 2; j < dim-4; j += 4) {
			//第一次
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;

			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;

			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;

			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;

			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
			index++;

			dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//第二次
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
			index++;

			dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//第三次
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
			index++;

			dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//第四次
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
			index++;

			dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

		}
		//处理这一行没处理完的像素点
		for (; j < dim-1; j++) {
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;

			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;

			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index].green = ((sum0_green+sum1_green+sum2_green)/9);
			index++;

			dst[index_].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;
		}

		//改变指针，指向下一行
		pixelA += dim;
		pixelB += dim;
		pixelC += dim;
		pixelD += dim;
		index += dim+2;
		index_ += dim+2;
	}
}



/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/


/*
  * 注册不同版本的smoot函数，只要注册了就全部会拿去跑分。
  *
  *
*/
void register_smooth_functions() 
{
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&smooth1, smooth_descr1);
    add_smooth_function(&smooth2, smooth_descr2);
    add_smooth_function(&smooth3, smooth_descr3);
    add_smooth_function(&smooth4, smooth_descr4);
    /* ... Register additional test functions here */
}

