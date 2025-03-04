package bin.app.main.home.Home;

import javax.swing.*;
import java.awt.*;

public class Home {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(Home::Run); // Garante que a UI seja criada na thread correta
    }

    public static void Start() { 
        // Criando a Janela
        JFrame F = new JFrame("Home");
        F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        F.setSize(800, 600);
        F.setLayout(new BorderLayout()); // Melhor layout para organização

        // Criando a Barra de Menu
        JMenuBar Mb = new JMenuBar();
        JMenu menu1 = new JMenu("Table");
        JMenu menu2 = new JMenu("Settings");
        JMenu menu3 = new JMenu("Create Table");
        

        //Table

        //Settings action 
        menu2.add((new JMenuItem(printAction));
        //Create Table action




        // Adicionando Menus à Barra de Menu
        Mb.add(menu1); Mb.add(menu3);
        Mb.add(menu2);

        // Criando o MainPainel
        JPanel MPanel = new JPanel(); 

        
        // Configurando a Janela
        F.setJMenuBar(Mb);
        F.add(MPanel, BorderLayout.CENTER);
        F.setVisible(true);
    }
}
