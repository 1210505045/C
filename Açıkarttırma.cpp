#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double deger;
    int sahip_no;
} Teklif;
typedef struct {
    Teklif* teklifler;
    int teklifveren_sayisi;
} A;
double odemeyi_hesapla(A a, int kazanan_no) {
    return a.teklifler[kazanan_no].deger ;
}
int main() {
    A a;
    double enyuksek_teklif;
    int kazanan_no;
    printf("Teklif veren sayisini giriniz: ");
    scanf("%d", &a.teklifveren_sayisi);    
	a.teklifler = (Teklif*)malloc(a.teklifveren_sayisi * sizeof(Teklif));
    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        printf("Teklif %d degerini ve sahip numarasini giriniz: ", i + 1);
        scanf("%lf %d", &a.teklifler[i].deger, &a.teklifler[i].sahip_no);
    }
    enyuksek_teklif = -1.0;
    kazanan_no = -1;
    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        if (a.teklifler[i].deger > enyuksek_teklif) {
            enyuksek_teklif = a.teklifler[i].deger;
            kazanan_no = i;
        }}
    if (kazanan_no != -1) {
        double odeme = odemeyi_hesapla(a, kazanan_no);
        printf("Kazanan Teklif Sahibi: %d\n", a.teklifler[kazanan_no].sahip_no);
        printf("Kazanan Teklifin Degeri: %f\n", a.teklifler[kazanan_no].deger);
        printf("Ödemeyi Göster: %f\n", odeme);
    } else {
        printf("Kazanan Teklif Sahibi Yok.\n");
    }
    free(a.teklifler);
    return 0;
}

