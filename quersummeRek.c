int quersummeRek(int x){
	if(x>=1){
		return x%10+quersummeRek(x/10);
	}
	return 0;
}
