public class recur{
	public static void main(String[] args){
		int x = power(3,5);
		System.out.printf("3 to the power of 5 is: %d",x);
	}
	public static int power(int base, int pow){
		if(pow==0)
			return 1;
		return base*power(base,pow-1);
	}
}
