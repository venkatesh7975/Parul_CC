// Write your code here!!

import java.util.*;

public class Main{
    static class TreeNode{
        int id;
        TreeNode left,right;
        public TreeNode(int id){this.id=id;}
    }
    private static List<Integer> inputData=new ArrayList<>();
    private static int index=0;
    private static StringBuilder output =new StringBuilder();

    private static TreeNode buildTree(){
        if(index>=inputData.size()) return null;
        int currentId=inputData.get(index++);
        if(currentId==-1 )return null;

        TreeNode root=new TreeNode(currentId);
        root.left =buildTree();
        root.right=buildTree();
        return root;
    }
    private static void traverse(TreeNode root,String type){
        if (root == null) return;

        switch(type){
            case "pre":
                output.append(root.id).append(" ");
                traverse(root.left,type);
                traverse(root.right,type);
                break;
            case "in":
                traverse(root.left,type);
                output.append(root.id).append(" ");
                traverse(root.right,type);
                break;
            case "post":
                traverse(root.left,type);
                traverse(root.right,type);
                output.append(root.id).append(" ");
                break;

        }
    }

    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        while(scanner.hasNextInt()){
            inputData.add(scanner.nextInt());
        }
        scanner.close();
        TreeNode root=buildTree();

        output.setLength(0);
        traverse(root,"pre");
        System.out.println(output.toString());

        output.setLength(0);
        traverse(root,"in");
        System.out.println(output.toString());

        output.setLength(0);
        traverse(root,"post");
        System.out.println(output.toString());
    }
}