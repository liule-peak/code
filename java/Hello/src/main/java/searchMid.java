public class package01 {
	public static void main(String [] args){
		int [] a = new int[]{1,2,3,4,5,11,13};
		int [] b = new int[]{6,7,8,9,10,12,14};
		int result = searchMid(a, b);
		System.out.print(result);
	}
 
	public static int searchMid(int [] a, int [] b){
		if(a.length != b.length){
			return -1;
		}
		int s1 = 0;
		int e1 = a.length - 1;
		int s2 = 0;
		int e2 = b.length - 1;
		int mid1,mid2;
		while(s1 < e1 && s2 < e2){
			mid1 = (s1 + e1) / 2;
			mid2 = (s2 + e2) / 2;
			if(a[mid1] == b[mid2]){
				return a[mid1];
			}
			if(a[mid1] < b[mid2]){
				s1 = mid1 + 1;
				e2 = mid2;
			}else{
				s2 = mid2 + 1;
				e1 = mid1;
			}
		}
		if(a[s1] < b[s2]){
			return a[s1];
		}else{
			return b[s2];
		}
	}
}