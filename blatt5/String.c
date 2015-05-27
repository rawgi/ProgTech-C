#include <stdio.h>
#include <String.h>
#include <stdbool.h>

String mkStringFromChars(_char* str){
	String result;
	result.length = 1; /*wie bekomme ich die länge raus? hab doch nur einen pointer...*/
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i<result.length; i++){
		result.data[i] = str[i];
	}

	return result;
}

String mkStringForLength(sizetype l){
	String result;
	result.length = l;
	result.data = malloc(l*sizeof(char));

	return result;
}

void strDelete(String this){
	free(this.data);
}

String strFromInt(int i){
	String result;
	int tmp = i;
	int length = 0;
	do{
		tmp = tmp/10;
		length++;
	}while(tmp>=1);
	result.length = length;
	result.data = malloc(length*sizeof(char));
	int c;
	for(c = length-1; c>0; c--){
		result.data[c] = (i%10)+48;
		i = i/10;
	}

	return result;
}

String strFromBool(bool b){
	if(b){
		mkStringFromChars("true");
	}
	return mkStringFromChars("false");
}

void strPrintLn(String this){
	printf("<tt>{length=%d;data=\"",this.length);
	int i;
	for(i = 0; i<this.length; i++){
		printf("%c",this.data[i]);
	}
	printf("\"}</tt>\n");
}

String strAppend(String this,String that){
	String result;
	result.length = this.length+that.length;
	result.data = malloc(result.length*sizeof(char));
	int ri = 0;
	int thisi;
	int thati;
	for(thisi = 0; thisi<this.length; thisi++){
		result.data[ri] = this.data(thisi);
		ri++;
	}
	for(thati = 0; thati<that.length; thati++){
		result.data[ri] = that.data(thati);
		ri++;
	}
	return result;
}

String strAppendInt(String this,int i){
	return strAppend(this,strFromInt(i));
}

String strReverse(String this){
	String result;
	result.length = this.length;
	result.data = malloc(result.length*sizeof(char));
	int ti = this.length-1;
	int ri;
	for(ri = 0; ri<result.length; ri++){
		result.data[ri] = this.data[ti];
		ti--;
	}

	return result;
}

String strMap(String this,char f(char)){
	String result;
	result.length = this.length;
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i<result.length; i++){
		result.data[i] = f(this.data[i]);
	}

	return result;
}

String strToUpperCase(String this){
	String result;
	result.length = this.length;
	int i;
	for(i = 0; i<result.length; i++){
		if(this.data[i]>=97 && this.data[i]<=122){
			result.data[i] = this.data[i]-32;
		}else{
			result.data[i] = this.data[i];
		}
	}

	return result;
}

String strToLowerCase(String this){
	String result;
	result.length = this.length;
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i<result.length; i++){
		if(this.data[i]>=65 && this.data[i]<=90){
			result.data[i] = this.data[i]+32;
		}else{
			result.data[i] = this.data[i];
		}
	}

	return result;
}

String strSubstring(String this,sizetype from, sizetype to){
	if(from>to){
		int tmp = from;
		from = to;
		to = tmp;
	}
	if(to > this.length){
		to = this.length;
	}
	String result;
	result.length = to-from;
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i< result.length; i++){
		result.data[i] = this.data[from];
		from++;
	}

	return result;
}


String strTrim(String this){
	String result;
	result.length = this.length;
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i<result.length; i++){
		result.data[i] = this.data[i];
	}
	bool found;
	do{
		found = false;
		if(strSubstring(result,0,2) == '\\n' || strSubstring(result,0,2) == '\\t'){
			result = strSubstring(result,3,result.length-1);
			found = true;
		}
		if(result.data[0] == ' '){
			result = strSubstring(result,1,result.length-1);
			found = true;
		}
		if(result.data[result.length-1] == ' '){
			result = strSubstring(result,0,result.length-2);
			found = true;
		}
		if(strSubstring(result,result.length-3,result.length-1) == '\\n' || strSubstring(result,result.length-3,result.length-1) == '\\t'){
			result = strSubstring(result,0,result.length-4);
			found = true;
		}
	}while(found);
	return result;
}

Ord strCompare(String this,String that){
	if(this == that) return eq;
	int i;
	bool larger = false;
	for(i = 0; i<this.length;i++){
		if(i>that.length || this.data[i] > that.data[i]){
			larger = true;
			break;
		}
	}
	if(larger) return gt;
	return lt;

}

bool strStartsWith(String this,String prefix){
	int i;
	for(i = 0; i<prefix.length; i++){
		if(this.data[i] != prefix.data[i]) return false;
	}
	return true;
}

bool strEndsWith(String this,String suffix){
	int i;
	for(i = 1; i<=suffix.length;i++){
		if(this.data[this.length-i] != suffix.data[suffix.length-i]) return false;
	}
	return true;
}

String strReplace(String this,_char oldChar, _char newChar){
	String result;
	result.length = this.length;
	result.data = malloc(result.length*sizeof(char));
	int i;
	for(i = 0; i<this.length; i++){
		if(this.data[i] == oldChar){
			result.data[i] = newChar;
		}else{
			result.data[i] = this.data[i];
		}
	}
	return result;
}
