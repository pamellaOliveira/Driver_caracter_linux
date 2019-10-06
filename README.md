# Driver_caracter_linux

#comandos 
#Criar módulo 
make -C /lib/modules/$(uname -r)/build M=$PWD modules

#Vê se criou o modulo 
ls -l

#Carregar módulo
sudo insmod ./3_driver_pamella.ko

#procurar módulo
lsmod | grep pamella
cat /proc/modules

#Criar Devices
sudo mknod -m 666 /dev/3_driver_pamella c 185 0

#Monitorar sistema
sudo tail -f /var/log/syslog

#verificar se foi criado o device
cat /dev/3_driver_pamella

#Abrir outro terminal e mandar mensagem
echo "teste" > /dev/3_driver_pamella
