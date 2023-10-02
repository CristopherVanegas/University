# from os import system
import os

ruta_cassandra_bin = "C:/Cassandra/apache-cassandra-3.11.10/bin"
os.chdir("{ruta_cassandra_bin}")

os.system("echo    [ console ] NODETOOL STATUS")
os.system("nodetool status")
os.system("nodetool snapshot taller")

ruta = "C:/Cassandra/apache-cassandra-3.11.10/data/data/taller/users-d16ccbd0d7a411edbfff45d04595b575"
os.chdir(f"{ruta_cassandra_bin}")
nueva_ruta = os.getcwd()
print(f"nuevo dir: {nueva_ruta}")



os.system("echo    [ console ] NODETOOL STATUS")
os.system("refresh taller users")
os.system("nodetool status")