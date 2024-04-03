void func3(int sum) {
	int* px;
	*px = sum;
}

void func2(char c) {
	int a = 34;
	int b = 45;
	int sum = a + b + c;
	func3(sum);
}

void func1() {
	char c = 'A';
	func2(c);
}

int main() {
 	func1();
 	return 0;
}
