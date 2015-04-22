int quersummeIt(int x){
	int y = 0;
	while(x>=1){
		y = y+x%10;
		x=x/10;
	}
	return y;
}
