/***
A robot is located at the top-left corner of a m x n grid (marked
‘Start’ in the diagram below). The robot can only move either down
or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
How many possible unique paths are there?
*/
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class uniquePaths
{
	public static final int r = 2;
	public static final int c = 2;
	
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		System.out.println("(" + r + "," + c + ")" + backtrack(r, c) );
	}
	public static int bt(int x, int y)
	{
		if (x==r && y==c) return 1;
		else if (x>r || y>c) return 0;
		else return bt(x+1,y) + bt(x,y+1);
	}
	public static int backtrack(int r, int c)
	{
		return bt(0,0);
	}
	public static int bt_dp ()
	{
		int [][] v = new int [r+2][c+2];
		//Vector<Vector<Integer>> v = new Vector<Vector<Integer>>(r+2, c+2);
		//Vector<Integer>[] v = new Vector<Integer>[c];
		for (int j=0; j<c+2; ++j) v[0][j] = 0;
		for (int i=0; i<r+2; ++i) v[i][0] = 0;
		v[0][1] = 1;
		
		for (int x=1; x<r+2; ++x) {
			for (int y=1; y<c+2; ++y) {
				v[x][y] = v[x-1][y] + v[x][y-1];
			}
		}
		return v[r+1][c+1];
	}
}

/***
    // creates fixed size 2D array with zeros
    int [] [] x = new int [50][50]; 

    // creates empty vector of vectors of integers
    // y is of type Vector<Vector<Integer>>
    // y.get(row) is of type Vector<Integer>>
    // y.get(row).get(col) is of type Integer
    Vector<Vector<Integer>> y = new Vector<Vector<Integer>>(); 

    // set the size of vector of vectors (number of rows)
    // each row will be null for now
    y.setSize(x.length);

    // enumerating rows
    for(int row=0; row<x.length; ++row) {

        log.info("row {}", row);

        // assign empty vector for row
        y.set(row, new Vector<Integer>());

        // set row size (number of columns)
        y.get(row).setSize(x[row].length);

        // enumerating columns of current row
        for(int col=0; col<x[row].length; ++col) {

            // setting the value for a cell
            y.get(row).set(col, x[row][col]);

        }
    }
*/    
