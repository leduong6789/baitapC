#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<string.h>

//Cau 1
long long A = 100000, X = 1000;
long Luong(int n) {
	if(n == 1 || n == 2) return A;
	if(n % 3 != 0) return Luong(n-1) + X;
	return (Luong(n-1) - (n-3)*X) * 1.1 + (n-2)*X;
}

long long LuongChinh(long long A, int n) {
	if( n == 1 || n == 2) return A;
	if(n <= 3) {
		return A * 1.1;
	}
	return LuongChinh(A*1.1, n-3);
}
long long L(int n) {
	return LuongChinh(A, n) + X*(n-2);
}
//Cau 2
int IsPrime(int n) {
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return 0;
	}
	return n > 1;
}
void CreatPrime(int *&fp1, int &n) {
	printf("Nhap n so Prime: ");
	scanf("%d", &n);
	fp1 = (int*) malloc(sizeof(int)*n);
	FILE * fp = fopen("Prime.txt", "wt");
	
	fprintf(fp, "%d\n", n);
	
	int dem = 0;
	int k = 2;
	while(dem < n) {
		if(IsPrime(k)) {
			fp1[dem++] = k;
			fprintf(fp, "%d ", k);
		}
		k++;
	}
	fclose(fp);
}
int Fibo(int n) {
	if(n <= 0) return 0;
	if(n == 1 || n == 2) return 1;
	return Fibo(n-1) + Fibo(n-2);
}
void CreatFibo(int *&fp2, int &m) {
	printf("Nhap m so Fibo: ");
	scanf("%d", &m);
	fp2 = (int*) malloc(sizeof(int)*m);
	FILE * fp = fopen("Fibo.txt", "wt");
	fprintf(fp, "%d\n", m);
	
	for(int i = 1; i <= m; i++) {
		int tam = Fibo(i);
		fp2[i-1] = tam;
		fprintf(fp,"%d ", tam);
	}
	fclose(fp);
}
void CreatPrimeFibo(int *fp1, int n, int *fp2, int m, int *&fp, int &k) {
	int tam;
	//Doc File Prime
	FILE * fo = fopen("Prime.txt", "rt");
	fscanf(fo,"%d\n", &n);
	fp1 = (int*) malloc(sizeof(int)*n);
	int i = 0, j;
	printf("Mang Prime: ");
	while(fscanf(fo, "%d ", &tam) != EOF) {
		fp1[i++] = tam;
		printf("%d ", tam);
	}
	printf("\n");
	fclose(fo);
	//Doc file Fibo
	fo = fopen("Fibo.txt", "rt");
	fscanf(fo,"%d\n", &m);
	fp2 = (int*) malloc(sizeof(int)*m);
	i = 0;
	printf("Mang Fibo: ");
	while(fscanf(fo, "%d ", &tam) != EOF) {
		fp2[i++] = tam;
		printf("%d ", tam);
	}
	printf("\n");
	fclose(fo);
	//Ghi file PrimeFibo.
	fo = fopen("PrimeFibo.txt", "wt");
	fp = (int*) malloc(sizeof(int)*(n*m));
	k = 0;
	i = 0, j = 0;
	while(i < n && j < m) {
		if(fp1[i] <= fp2[j]) {
			fp[k++] = fp1[i];
			while(fp1[i] == fp2[j]) j++;
			i++;
		}
		else{
			fp[k++] = fp2[j++];
		}
	}
	if(i == n) {
		for(int i = j; i < m; i++) {
			fp[k++] = fp2[i];
		}
	}
	else{
		for(int j = i; j < n; j++) {
			fp[k++] = fp1[j];
		}
	}
	//Xoa trung gan nhau
	j = 0;
	for(i = 0; i < k; i++) {
		if(fp[i] != fp[i+1] || i == (k-1)) {
			fp[j++] = fp[i];
		}
	}
	k = j;
	
	fprintf(fo, "%d\n", k);
	for(i = 0; i < k; i++) {
		fprintf(fo, "%d ", fp[i]);
	}
	printf("Mang Tong PrimeFibo: ");
	for(i = 0; i < k; i++) {
		printf( "%d ", fp[i]);
	}
	fclose(fo);
}
//Cau 3
typedef struct {
	char MVId[6];
	char MVName[26];
	char Author[26];
	long long View;	
}MV;
void InputMVArr(MV MVArr[], int &n) {
	printf("Nhap so MV: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		printf("Nhap ma MV: ");
		scanf("%s", MVArr[i].MVId);
		while(getchar() != '\n');
		printf("Nhap ten MV: ");
		fgets(MVArr[i].MVName, sizeof(MVArr[i].MVName), stdin);
		printf("Nhap ten tac gia: ");
		fgets(MVArr[i].Author, sizeof(MVArr[i].Author), stdin);
		printf("Nhap so View: ");
		scanf("%lld", &MVArr[i].View);
		for(int j = 0; j < 26; j++) {
			if(MVArr[i].MVName[j] == '\n'){
				MVArr[i].MVName[j] = '\0';
			}
		}
		for(int j = 0; j < 26; j++) {
			if(MVArr[i].Author[j] == '\n'){
				MVArr[i].Author[j] = '\0';
			}
		}
	}
}
void OutputMVArr(MV MVArr[], int n) {
	printf("STT  Ma Music Video  Ten Music Video           Tac Gia                   So Luong View\n");
	for(int i = 0; i < n; i++) {
		printf("%-5d%-16s%-26s%-26s%lld\n", i+1, MVArr[i].MVId, MVArr[i].MVName, MVArr[i].Author, MVArr[i].View);
	}
}
void ViewNhieuNhat(MV MVArr[], int n) {
	long long maxview = 0;
	for(int i = 0; i < n; i++) {
		if(maxview < MVArr[i].View) {
			maxview = MVArr[i].View;
		}
	}
	printf("STT  Ma Music Video  Ten Music Video           Tac Gia                   So Luong View\n");
	int dem = 0;
	for(int i = 0; i < n; i++) {
		if(MVArr[i].View == maxview) {
			dem++;
			printf("%-5d%-16s%-26s%-26s%lld\n", i+1, MVArr[i].MVId, MVArr[i].MVName, MVArr[i].Author, MVArr[i].View);
		}
	}
	if(dem == 0) printf("Khong co MV.");
}
void XoaMV_TNOAA(MV MVArr[], int &n) {
	char ac[] = "There's No One At All";
	for(int i = 0; i < n; i++) {
		if(strcmp (MVArr[i].MVName, ac) == 0) {// -1 0 1
			for(int j = i; j < n-1; j++) {
				MVArr[i] = MVArr[i+1];
			}
			n--;
		}
	}
}
int main() {
	int chon;
	printf("Nhap cau: ");
	lai:
	scanf("%d", &chon);
	switch(chon) {
		case 1:
			int n;
			printf("Nhap nam: ");
			scanf("%d", &n);
			printf("Luong sau %d nam la: %lld\n", n, L(n));
			printf("Luong sau %d nam la: %lld", n, Luong(n));
			break;
		case 2:
			int m, k, *fp1, *fp2, *fp;
			CreatPrime(fp1, n);
			CreatFibo(fp2, m);
			CreatPrimeFibo(fp1, n, fp2, m, fp, k);
			free(fp1);
			free(fp2);
			free(fp);
			break;
		case 3:
			MV MVArr[100];
			int chon3;
			printf("Menu:\n 1. Nhap va Xuat mang\n 2. Xuat MV co View cao nhat\n 3. Xoa MV There's No One At All\n 4. Thoat\nMoi nhap lua chon: ");
			scanf("%d", &chon3);
			switch(chon3) {
				case 1:
					InputMVArr(MVArr, n);
					OutputMVArr(MVArr, n);
					break;
				case 2:
					ViewNhieuNhat(MVArr, n);
					break;
				case 3:
					XoaMV_TNOAA(MVArr, n);
					break;
				case 4:
					break;
				default:
					printf("Nhap sai roi\nMoi nhap lai: ");
			}
			break;
		default:
			printf("Nhap sai roi ban eyy!!!\nNhap lai di ban: ");
			goto lai;
	}
	return 0;
}
