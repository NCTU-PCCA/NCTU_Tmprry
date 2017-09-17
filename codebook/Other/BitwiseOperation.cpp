inline int pop_count(int x){
	x = (0x55555555&x) + (0x55555555&(x>>1));
	x = (0x33333333&x) + (0x33333333&(x>>2));
	x = (0x0F0F0F0F&x) + (0x0F0F0F0F&(x>>4));
	x = (0x00FF00FF&x) + (0x00FF00FF&(x>>8));
	x = (0x0000FFFF&x) + (0x0000FFFF&(x>>16));
	return x;
}
