import java.util.Scanner;

public class FIFO{
    
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int ref[],mem[][],buffer[],rf,fr,fault=0,hit=0,pointer=0;
        System.out.print("Enter Frames number");
        fr=sc.nextInt();
        System.out.println("Enter length refer");
        rf=sc.nextInt();
        ref=new int[rf];
        mem=new int[rf][fr];
        buffer=new int[fr];
        
        for(int i=0;i<rf;i++)
        {
            ref[i]=sc.nextInt();
        }
        for(int i=0;i<fr;i++)
        {
            buffer[i]=-1;
        }
        
        for(int i=0;i<rf;i++)
        {
            int search=-1;
            for(int j=0;j<fr;j++)
            {
                if(buffer[j]==ref[i])
                {
                    hit++;
                    search=1;
                    break;
                }
            }
            if(search==-1)
            {
                buffer[pointer]=ref[i];
                pointer=(pointer+1)%fr;
                fault++;
            }
            
            for(int j=0;j<fr;j++)
            {
                mem[i][j]=buffer[j];
            }
            
        }
        for(int i=0;i<fr;i++)
        {
            for(int j=0;j<rf;j++)
            {
                System.out.printf("%3d",mem[j][i]);
            }
            System.out.println();
        }
        System.out.println("the hit"+hit);
        System.out.println("the ratio"+(float)((float)hit/rf));
        System.out.println("the faults"+fault);
    }
    
}