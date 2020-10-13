//重构下面的orderbook_generation函数需要使用的交换两个指针的功能 
void swap(struct Project **a, struct Project **b)
{
	struct Project *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
