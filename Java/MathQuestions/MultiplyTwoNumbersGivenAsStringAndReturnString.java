package Java.MathQuestions;

class Solution {
    public String multiply(String num1, String num2) {
        if((num1.length()==1 && num1.charAt(0)-48==0) || (num2.length()==1 && num2.charAt(0)-48==0))
            return "0";
        int l1=num1.length(),l2=num2.length();
        int[] arr=new int[l1+l2];
        int count=0,l3=l1+1;
        for(int i=l2-1;i>=0;i--)
        {
            int carry=0,counter=0;
            int[] temp=new int[l1+1];
            for(int j=l1-1;j>=0;j--)
            {
                int num=carry+(num1.charAt(j)-48)*(num2.charAt(i)-48);
                carry=num/10;
                temp[counter]=num%10;
                counter++;
            }
            if(carry>0)
            {
                temp[counter]=carry;
            }
            carry=0;
            int k=0;
            for(k=0;k<temp.length;k++)
            {
                int temp_add=carry+temp[k]+arr[k+count];
                carry=temp_add/10;
                arr[k+count]=temp_add%10;
            }
            if(carry>0)
            {
                arr[k+count]+=carry;
            }
            l3--;
            count++;
        } 
    String ans="";
    int totalsize=l1+l2-1;
    int i=totalsize;
    while(i>=0)
    {
        if(arr[i]!=0)
            break;
        i--;
    }
    while(i>=0)
    {
        ans+=arr[i];
        i--;
    }
    return ans;
}
}
