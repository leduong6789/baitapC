#include <stdio.h>
int main(){
	float toan,van,sinh,hoa,ly,dtb,tong_diem,dc,diem_chuan_chuyen;
	char chuyen;
	do{
		printf("Nhap diem toan: ");
		scanf("%f",&toan);
	}while(toan<0||toan>10);
	do{
		printf("Nhap diem van: ");
		scanf("%f",&van);
	}while(van<0||van>10);
	do{
		printf("Nhap diem sinh: ");
		scanf("%f",&sinh);
	}while(sinh<0||sinh>10);
	do{
		printf("Nhap diem ly: ");
		scanf("%f",&ly);
	}while(ly<0||ly>10);
	do{
		printf("Nhap diem hoa: ");
		scanf("%f",&hoa);
	}while(hoa<0||hoa>10);
	do{
		printf("Nhap mon chuyen (S, H, L): ");
    	scanf(" %c", &chuyen);
    	if(chuyen != 'S' && chuyen !='H' && chuyen !='L'){
    		char trl;
    		printf("Ban co muon nhap lai mon chuyen khong ? (y/n)");
    		scanf(" %c",&trl);
    		if(trl=='n' || trl=='N'){
    			return 0;
    			break;
			}
				
		}
	}while(chuyen != 'S' && chuyen !='H' && chuyen !='L');
    if (chuyen == 'S') {
        tong_diem = toan * 2 + van * 2 +  hoa + ly + sinh * 3;
        dtb = tong_diem / 9;
    } else if (chuyen == 'H') {
        tong_diem = toan * 2 + van * 2 + sinh + ly + hoa * 3;
        dtb = tong_diem / 9;
    } else if (chuyen == 'L') {
        tong_diem = toan * 2 + van * 2 + sinh + hoa + ly * 3;
        dtb = tong_diem / 9;
    }
    printf("Diem trung binh cua hoc sinh la: %.2f\n",dtb);
    if(dtb>=9&&((toan>=8 && van>=8 && sinh>=8 && hoa>=8 && ly>=8)))
		printf("Gioi.\n");
	else if(dtb>=7&&((toan>=6 && van>=6 && sinh>=6 && hoa>=6 && ly>=6)))
		printf("Kha.\n");
	else if(dtb>=5&&((toan>=4 && van>=4 && sinh>=4 && hoa>=4 && ly>=4)))
		printf("Trung binh.\n");
	else printf("Yeu.\n");
	do{
		printf("Hay nhap diem chuan: ");
		scanf("%f",&dc);}while(dc<=0||dc>10);
	do{
		printf("Nhap diem chuan mon chuyen: ");
    	scanf("%f", &diem_chuan_chuyen);
	}while(diem_chuan_chuyen<=0||diem_chuan_chuyen>10);
    if (tong_diem >= dc && ((chuyen == 'S' && sinh >= diem_chuan_chuyen) || (chuyen == 'H' && hoa >= diem_chuan_chuyen) || (chuyen == 'L' && ly >= diem_chuan_chuyen))) {
        printf("Hoc sinh do!\n");
    } else if (tong_diem >= dc) {
        printf("Hoc sinh xet lai!\n");
    } else {
        printf("Hoc sinh rot!\n");
    }

    return 0;

	
	if(tong_diem>=dc) printf("Dau.");
	else printf("Rot.");
	
	
}
