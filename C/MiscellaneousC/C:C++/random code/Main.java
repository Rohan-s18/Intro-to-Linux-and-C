import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame myFrame = new JFrame();
        myFrame.setSize(200,300);
        myFrame.setVisible(true);
        JTextArea myText = new JTextArea();
        myText.setText("Hello World!");
        myFrame.getContentPane().add(myText);
    }
}
