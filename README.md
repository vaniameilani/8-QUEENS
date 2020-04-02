Kecerdasan-Buatan

8 Queens adalah salah satu permainan strategi sederhana berdasarkan pada salah satu aturan catur, menunjukkan perilaku ratu di papan. 
Untuk memenangkan permainan ini, maka kita harus menemukan tempat 8 Queens di kotak yang tepat di papan catur, dimana tidak ada yang boleh menyerang dari arah manapun
(atas, bawah, kanan, kiri, diagonal). 

Dalam penyelesaiannya dapat digunakan beberapa solusi, salah satunya yaitu dengan DFS (Depth First Search), pencarian yang dilakukan pada satu node dalam setiap level dari yang paling kiri. 
Jika pada level yang paling dalam, solusi belum ditemukan, maka pencarian dilanjutkan pada node sebelah kanan. 
Node yang kiri dapat dihapus dari memori. Jika pada level yang paling dalam tidak ditemukan solusi, maka pencarian dilanjutkan pada level sebelumnya. 
Demikian seterusnya sampai ditemukan solusi. Jika solusi ditemukan maka tidak diperlukan proses backtracking (penelusuran balik untuk mendapatkan jalur yang dinginkan).

Untuk program dari 8 Queens dengan DFS  :
```
int place (int pos){
	int i;
	for (i=1; i<pos; i++){
		if ((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))))
			return 0;			// if a queen exists in same column or diagonally
	}
	return 1;
}
```
Fungsi ini untuk memeriksa apakah ada Queen yang lain, yang saling menyerang.

```
void queen (int n){
	int k=1;	
	a[k]=0;		
	while(k!=0){ 
		do{
			a[k]++;
		}
		while ((a[k]<=n)&&!place(k)); 
		if (a[k]<=n){
			if (k==n)
				print(n);
			else {
				k++;
				a[k]=0;
			}
		}
		else 
			k--;
	}
}

```
Fungsi untuk meletakkan queen di kotak yang tepat agar tidak saling menyerang

```
//	int n;
//	printf ("Enter the number of Queen : ");
//	scanf ("%d", &n);
```
Program diatas digunakan apabila ingin menggunakan jumlah Queen yang lain, selain n=8.

#### PENJELASAN ####
Mula mula, Queen pertama diletakkan di kolom pertama dan baris pertama. Kemudian, Queen-1 diperiksa di segala arah apakah ada Queen lainnya yang menyerang. Jika tidak ada, maka dilanjutkan dengan meletakkan Queen-2 di baris pertama dan kolom kedua. Kemudian, dicek kembali untuk Queen-2 apakah saling menyerang dengan Queen lainnya. Apabila terdapat penyerangan, maka Queen-2 turun ke baris kedua, dicek kembali terus menerus, hingga Queen-2 menemukan kotak yang tepat dimana tidak saling menyerang dengan Queens yang ada di papan catur tersebut. Proses tersebut berlangsung hingga Queen-8. 
Dalam program ini , terdapat 92 solutions pada 8-Queens problem.
~
