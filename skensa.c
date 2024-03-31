#include <stdio.h>
#include <string.h>
#include <time.h>

struct Barang {
    char nama[20];
    int jumlah;
};


void generatefile(char *namafile,char *tanggal,char *idstruk) {
    time_t t = time(NULL);
    struct tm *waktuSekarang = localtime(&t);
    strftime(namafile, 50, "C:/belajar C/STRUK/struk_%Y%m%d%H%M%S.txt", waktuSekarang);
    strftime(tanggal, 50, "%a %d %H:%M:%S %Y",waktuSekarang);
    strftime(idstruk, 50, "%Y%m%d%H%M%S", waktuSekarang);
}


int main(){
    int pilihan, jumlah, uang,temp;
    int urutan[5];
    struct Barang barang[5] = {{"Buku Tulis", 0}, {"Pensil", 0}, {"Penghapus", 0}, {"Penggaris", 0}, {"Bujur Sangkar", 0}};
    int total_harga = 0;
    int nomor = 1;
    float total_diskon = 0;
    float harga, diskon, kembalian;
    char namafile[50];
    char tanggal[50];
    char idstruk[50];
    generatefile(namafile,tanggal,idstruk);


    printf("================================================\n");
    printf("    SELAMAT DATANG DI TOKO SKENSA         \n");
    printf(" Silahkan pilih barang yang Anda inginkan \n");
    printf("==========================================\n\n\n\n");

    do {
        printf("=================================================\n");
        printf("   No |          Barang           |    Harga     \n");
        printf("=================================================\n");
        printf("   1. |         Buku Tulis        |   Rp.5000   \n");
        printf("   2. |         Pensil            |   Rp.2000   \n");
        printf("   3. |         Penghapus         |   Rp.1000   \n");
        printf("   4. |         Penggaris         |   Rp.1000   \n");
        printf("   5. |         Bujur Sangkar     |   Rp.500    \n");
        printf("=================================================\n\n");
        printf("99.Struk Pembayaran\n");
        printf("55.Reset Pilihan\n");
        printf("00.Keluar\n\n");
        printf("=================================================\n\n");
        printf("Input Pilihan yang Anda Inginkan:");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukan jumlah item:");
                scanf("%d", &jumlah);
                barang[0].jumlah += jumlah;
                harga = jumlah * 5000;
                total_harga += harga;
                break;

            case 2:
                printf("Masukan jumlah item:");
                scanf("%d", &jumlah);
                barang[1].jumlah += jumlah;
                harga = jumlah * 2000;
                total_harga += harga;
                break;

            case 3:
                printf("Masukan jumlah item:");
                scanf("%d", &jumlah);
                barang[2].jumlah += jumlah;
                harga = jumlah * 1000;
                total_harga += harga;
                break;

            case 4:
                printf("Masukan jumlah item:");
                scanf("%d", &jumlah);
                barang[3].jumlah += jumlah;
                harga = jumlah * 1000;
                total_harga += harga;
                break;

            case 5:
                printf("Masukan jumlah item:");
                scanf("%d", &jumlah);
                barang[4].jumlah += jumlah;
                harga = jumlah * 500;
                total_harga += harga;
                break;

            case 99:
                for(int i = 0; i < 5; i++)
                {
                    urutan[i] = i;
                }
                for(int i = 0; i < 5 - 1; i++)
                {
                    for(int j = 0; j < 5 - i - 1; j++)
                    {
                        if(barang[urutan[j]].jumlah < barang[urutan[j+1]].jumlah)
                        {
                            temp = urutan[j];
                            urutan[j] = urutan[j+1];
                            urutan[j+1] = temp;
                        }
                    }
                }
                printf("=======================================REKAPAN BARANG========================================\n");
                printf("=============================================================================================\n");
                printf(" No | Jumlah |          Barang          |    Harga     | Total Harga |     Diskon      |\n");
                printf("=============================================================================================\n");


                for (int j = 0; j < 5; j++) {
                    int index = urutan[j];
                    if (barang[index].jumlah > 0) {
                        harga = barang[index].jumlah * (index == 0 ? 5000 : (index == 1 ? 2000 : (index == 2 ? 1000 : (index == 3 ? 1000 : 500))));
                        diskon = (barang[index].jumlah >= 5) ? (harga * 0.15) : ((barang[index].jumlah >= 3) ? (harga * 0.10) : 0.0);
                        total_diskon += diskon;

                        printf("%3d | %6d | %24s | Rp.%9d | Rp.%9.2f | Rp.%9.2f |\n", j + 1, barang[index].jumlah, barang[index].nama, (index == 0 ? 5000 : (index == 1 ? 2000 : (index == 2 ? 1000 : (index == 3 ? 1000 : 500)))), harga, (barang[index].jumlah >= 3 || barang[index].jumlah >= 5) ? diskon : 0.0);
                    }
                }
                printf("=========================================================================\n");
                printf("\nTotal Diskon = %.2f\n", total_diskon);
                printf("Total Harga = %d\n", total_harga);
                printf("Total Harga Setelah Diskon = %.2f\n", total_harga - total_diskon);
                printf("=========================================================================\n");
                printf("Masukkan Jumlah Uang Anda:");
                scanf("%d", &uang);
                if (uang < total_harga - total_diskon) {
                    printf("Uang Anda Kurang\n");
                } else {
                    kembalian = uang - (total_harga - total_diskon);
                    printf("\nKembalian Anda: %.2f\n", kembalian);
                }


                //CETAK STURK
                FILE *file = fopen(namafile, "w");
                if (file == NULL) {
                   printf("Gagal mencetak struk\n");
                      return;
                }

                fprintf(file,"                                       TOKO SKENSA                                           \n");
                fprintf(file,"                            JL HOS Cokroaminoto No.84,Denpasar                               \n");
                fprintf(file,"                                          BALI                                               \n");
                fprintf(file,"                                    TELP: 0816285791                                         \n");
                fprintf(file,"ID Struk:%s                                                                                  \n",idstruk);
                fprintf(file,"=============================================================================================\n");
                fprintf(file,"=============================================================================================\n");
                fprintf(file," No | Jumlah |          Barang          |    Harga     | Total Harga |     Diskon      |\n");
                fprintf(file,"=============================================================================================\n");


                for (int j = 0; j < 5; j++) {
                    int index = urutan[j];
                    if (barang[index].jumlah > 0) {
                        harga = barang[index].jumlah * (index == 0 ? 5000 : (index == 1 ? 2000 : (index == 2 ? 1000 : (index == 3 ? 1000 : 500))));
                        diskon = (barang[index].jumlah >= 5) ? (harga * 0.15) : ((barang[index].jumlah >= 3) ? (harga * 0.10) : 0.0);

                        fprintf(file,"%3d | %6d | %24s | Rp.%9d | Rp.%9.2f | Rp.%9.2f |\n", nomor++, barang[index].jumlah, barang[index].nama, (index == 0 ? 5000 : (index == 1 ? 2000 : (index == 2 ? 1000 : (index == 3 ? 1000 : 500)))), harga, (barang[index].jumlah >= 3 || barang[index].jumlah >= 5) ? diskon : 0.0);
                    }
                }
                fprintf(file,"=========================================================================\n");
                fprintf(file,"\nTotal Diskon = %.2f\n", total_diskon);
                fprintf(file,"Total Harga = %d\n", total_harga);
                fprintf(file,"Total Harga Setelah Diskon = %.2f\n", total_harga - total_diskon);
                fprintf(file,"=========================================================================\n");
                fprintf(file,"Masukkan Jumlah Uang Anda: %d", uang);
                fprintf(file,"\nKembalian Anda: %.2f\n\n\n\n", kembalian);
                fprintf(file,"Waktu/Hari: %s", tanggal);

                fclose(file);

                break;

            case 55:
                total_harga = 0;
                total_diskon = 0.0;
                for (int j = 0; j < 5; j++) {
                    barang[j].jumlah = 0;
                }
                nomor = 1;
                printf("Pilihan telah direset.\n");
                break;

        }
    } while(pilihan != 0);

    return 0;
}
