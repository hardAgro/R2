# Diagnóstico de Estresses Abióticos (DEA)

# Características
- Sistema autônomo de sensoriamento e alerta sobre condições de umidade do solo, condutividade elétrica da solução do solo e infestação de mosca das frutas. </br>
- Alerta sobre condições anormais de salinidade do solo (presença ou ausência de sais), através do monitoramento remoto de condutibilidade elétrica de sua solução aquosa. </br>
- Alerta sobre condições anormais de umidade do solo através do monitoramento remoto da água livre do solo, respeitando suas características físicas. </br>
- Alerta sobre condições anormais de MAD (infestação de mosca das frutas) através de monitoramento armadilhas eletrônicas de baixo custo.

# Pré-requisitos
1 - APACHE 2.0 + (Modo de escrita URL atívo) </br>
2 - MYSQL 5.7 </br>
3 - Arduino Software (IDE) 2.0

# Instalação 
1 - Faça o download dos arquivos e descompacte o arquivo deapp.zip </br>
2 - Copie a pasta Deapp para a pasta do localhost no Apache. </br>
3 - Edite o arquivo conexao.php e configure o usuário root e adcione a senha de acesso ao MYSQL, se houve. </br>
4 - Crie um novo banco de dados no MYSQL com o nome DEA. </br>
5 - Importe o conteúdo do arquivo deapp.sql para o MYSQL. </br>
6 - Teste a aplicação abrindo a pasta no localhost\deapp </br>
7 - Faça bom uso da nossa aplicação! ;)

# Licenças
DEA APP (GPLv2)

PHP (PHP License v3.01)

MYSQL (GPL)

APACHE (Apache License - GPL 3.0)

BOOTSTRAP (MIT)

ARDUINO SOFTWARE (IDE) (GNU)
