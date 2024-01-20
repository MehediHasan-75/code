
import java.io.*;
import java.util.*;
import java.awt.geom.*;

/**
 * Solution to Alternate Bracket Notation
 * 
 * @author vanb
 */
public class bracketnotation_vanb
{

    
    /** We need to keep track of whether the width of a node's representation changed. */
    public boolean changed;
    
    /**
     * A Node of a parse tree of balanced parentheses.
     * 
     * @author vanb
     */
    public class Node
    {
        /** The start, end, and width of the "start:end:" prefix for this node. */
        public int start=0, end=0, width=4;
        
        /** This node's children */
        List<Node> children = new LinkedList<Node>();
        
        /**
         * Adjust the start, end, and width of this node.
         * 
         * @param p Position in the result String of the start of this node's representation
         * @return Position in the result String of the end of this node's representation, including children
         */
        public int adjust( int p )
        { 
            // This is how wide (we currently think) this node's prefix is. 
            p += width;
            
            // Our children's representation starts here, at our 'start' value
            start = p;
            for( Node child : children ) p = child.adjust( p );
            end = p;
            
            // if our width changed, that can change everything.
            // We'll need to do it all again.
            // The width of our prefix is the width of the two numbers plus 2 (for the comma and colon)
            int newwidth = log(start) + log(end) + 2; 
            if( newwidth!=width ) 
            {
                width=newwidth;
                changed = true;
            }
            
            return p;
        }
        
        /**
         * Create an Alternate Bracket Notation representation
         * of the subtree rooted at this node.
         * 
         * @return String representation
         */
        public String toString()
        {
            String s = "" + start + "," + end + ":";
            for( Node child : children ) s += child.toString();
            return s;
        }
    }
    
    /** Line of input, as character */
    char line[];
    
    /** Position in the line as we're parsing */
    int pos;
    
    /**
     * Parse a balanced set of parentheses.
     * @return A node, which is the root of a tree of a set of parentheses.
     */
    public Node parse()
    {
        Node node = new Node();
        
        // Go past the '('
        ++pos;
        
        // As long as we see a '(', there's another child
        while( line[pos]=='(' ) node.children.add( parse() );
        
        // Go past the ')'
        ++pos;

        return node;
    }
        
    /**
     * Driver.
     * @throws Exception
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        // There may be more than one tree here.
        // For example, ()()() has 3.
        // () (()) (()()) () () has 5 (spaces added for clarity)
        List<Node> roots = new LinkedList<Node>();
        
        // Read the input, parse it into a sequence of trees.
        line = sc.next().toCharArray();
        pos=0;
        while( pos<line.length ) roots.add( parse() );
        
        do
        {
            // Build the string, adjusting it every time we have to 
            // change the width of a node.
            changed = false;
            int p=0;
            for( Node root : roots ) p = root.adjust( p );
        } while( changed );
        
        // Build and print the answer.
        String answer = "";
        for( Node root : roots ) answer += root.toString();
        ps.println( answer );  
    }
        
    /**
     * @param args
     */
    public static void main( String[] args ) throws Exception
    {
        new bracketnotation_vanb().doit();
    }   
}