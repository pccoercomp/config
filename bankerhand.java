import java.util.Scanner;
public class Bankers{
    private int need[][],allocate[][],max[][],avail[][],np,nr;
    
    private void input(){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter no of process and resource: ");
        np=sc.nextInt();
        nr=sc.nextInt();
        need=new int[np][nr];
        allocate=new int[np][nr];
        max=new int[np][nr];
        avail=new int[1][nr];
        
        System.out.println("Enter allocation matrix-->");
        for(int i=0;i<np;i++)
        {
            for(int j=0;j<nr;j++)
            {
                allocate[i][j]=sc.nextInt();
            }
        }
        
        System.out.println("Enter max matrix-->");
        for(int i=0;i<np;i++)
        {
            for(int j=0;j<nr;j++)
            {
                max[i][j]=sc.nextInt();
            }
        }
        
        System.out.println("Enter available matrix-->");
        for(int i=0;i<nr;i++)
        {
            avail[0][i]=sc.nextInt();
        }
        sc.close();
    }
    
    private int[][] calc_need(){
        for(int i=0;i<np;i++)
        {
            for(int j=0;j<nr;j++)
            {
                need[i][j]=max[i][j]-allocate[i][j];
            }
        }
        return need;
    }
    
    private boolean check(int i){
        for(int j=0;j<nr;j++)
        {
            if(avail[0][j]<need[i][j])
            {
                return false;
            }
        }
        return true;
    }
    
    public void isSafe(){
        input();
        calc_need();
        boolean done[]=new boolean[np];
        int j=0;
        
        while(j<np)
        {
            boolean allocated=false;
            for(int i=0;i<np;i++)
            {
                if(!done[i] && check(i))
                {
                    for(int k=0;k<nr;k++)
                    {
                        avail[0][k]=avail[0][k]+max[i][k]-need[i][k];
                    }
                    System.out.println("Allocated process:"+i);
                    allocated=done[i]=true;
                    j++;
                }
            }
            if(!allocated) break;
        }
        if(j==np){
            System.out.println("\nSafely allocated");
        }
        else{
            System.out.println("All process cant be allocated safely");
        }
        
    }
    
    public static void main(String[] args){
        new Bankers().isSafe();
    }
    
}