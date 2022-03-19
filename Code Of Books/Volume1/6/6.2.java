import java.io.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String[]args) throws IOException
    {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line;

        line = stdin.readLine();
        int cases = Integer.parseInt(line);

        while (cases > 0)
        {
            line = stdin.readLine();
            System.out.println(getPieces(line));
            cases--;
        }
    }

    public static BigInteger getPieces(String line)
    {
        BigInteger n = new BigInteger(line);

        BigInteger pieces = n.pow(4);
        pieces = pieces.subtract(n.pow(3).multiply(BigInteger.valueOf(6)));
        pieces = pieces.add(n.pow(2).multiply(BigInteger.valueOf(23)));
        pieces = pieces.subtract(n.multiply(BigInteger.valueOf(18)));
        pieces = pieces.add(BigInteger.valueOf(24)).divide(BigInteger.valueOf(24));

        return pieces;
    }
}
