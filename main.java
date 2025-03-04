package bin.Main;

import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) { Run();}

    public static void Run() { 
        // Criando a Janela
        JFrame F = new JFrame("Login Page:");
        F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        F.setSize(800, 600);
        F.setLayout(new BorderLayout()); // Melhor layout para organização

        // Criando o Painel Principal
        JPanel MPanel = new JPanel(new GridLayout(3, 1, 10, 10)); // Layout mais organizado

        // Campo Nome
        JPanel PName = new JPanel();
        PName.add(new JLabel("Nome:"));
        JTextField txtName = new JTextField(15);
        PName.add(txtName);

        // Campo Senha
        JPanel PSenha = new JPanel();
        PSenha.add(new JLabel("Senha:"));
        JPasswordField Pass = new JPasswordField(15); // Ajustei para 15 para manter consistência
        PSenha.add(Pass);

        // Botão para Enviar Dados
        JButton BSubmit = new JButton("Enviar");
        BSubmit.addActionListener(e -> {
            String nome = txtName.getText().trim();
            String senha = new String(Pass.getPassword()).trim();
            
            //Entrada Oficial
            /*if (nome.toLowerCase() = "naylor" && senha.toLowerCase() === "naylor" ) {
             JOptionPane.showMessageDialog(F, "Nome: " + nome + "\nSenha: " + senha, "Sucesso", 
             JOptionPane.INFORMATION_MESSAGE);
              
            } 

            else {
                JOptionPane.showMessageDialog(F, "Erro Necessario colocar 'naylor' no login e senha", 
                JOptionPane.ERROR_MESSAGE);
              }

            if (nome.isEmpty() || senha.isEmpty()) {
                JOptionPane.showMessageDialog(F, "Os campos não podem estar vazios!", "Erro", 
                JOptionPane.ERROR_MESSAGE);
            }*/

        });

        // Adicionando Componentes ao Painel Principal
        MPanel.add(PName);
        MPanel.add(PSenha);
        MPanel.add(BSubmit);

        // Configurando a Janela
        F.add(MPanel, BorderLayout.CENTER);
        F.setVisible(true);
    }
}
