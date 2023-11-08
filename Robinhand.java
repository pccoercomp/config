import java.util.*;
public class round
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n;
        int arr[],comp[],cpu[],ncpu[];
        System.out.print("Enter number of process you want to execute : ");
        n=sc.nextInt();
        arr=new int[n];
        comp=new int[n];
        cpu=new int[n];
        ncpu=new int[n];
        int v[]=new int[n];
        for(int i=0;i<n;i++)
        {
            v[i]=0;
            System.out.print("Enter arrival time of P"+(i+1)+": ");
            arr[i]=sc.nextInt();
            System.out.print("Enter cpu time of P"+(i+1)+": ");
            cpu[i]=sc.nextInt();
            ncpu[i]=cpu[i];
        }
        int qt=2;
        int sum=arr[0];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        v[0]=1;
        while(!q.isEmpty())
        {
            int tp=0;
            int k=q.poll();
            if(ncpu[k]>qt)
            {
                sum+=qt;
                ncpu[k]=ncpu[k]-qt;
            }
            else {
                sum+=ncpu[k];
                ncpu[k]=0;
                comp[k]=sum;
            }
            for(int i=0;i<n;i++)
            {
                if(ncpu[i]>0 && v[i]==0 && arr[i]<=sum)
                {
                    q.offer(i);
                    v[i]=1;
                }
            }
            v[k]=0;
            if(ncpu[k]>0){
             q.offer(k);
             v[k]=1;
            }
        }
        System.out.println("Completion: ");
        for(int i=0;i<n;i++) 
        System.out.println(comp[i]);
    }
}