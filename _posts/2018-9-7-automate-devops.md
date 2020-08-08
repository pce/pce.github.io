# Automate devops with Fabric

This "recipe" allows "remote" Dev-Ops from a local machine with Fabric 2.3.1.

One way is to `pip install fabric`. 


Creating a [fabric](https://www.fabfile.org) fabfile:


~~~python
from fabric import Connection
from fabric import task




@task
def space(c):
    result = c.run('df -h')


@task
def devops(c):
    space(c)

~~~



The fabfile reads `~/.ssh/config`, where the Host: web1 (example.com) is configured.

Set up the hosts to automate:  ` cat ~/.ssh/config`        

    
    Host web1
      HostName example.com
      User foobar
      # or identyfile:
      # IdentitiesOnly yes
      # IdentityFile ~/.ssh/web1
    
    
    

The -H flag is the Host of ssh-config and `devops` the task:

`fab --prompt-for-login-password -Hweb1 devops`

    Enter login password for use with SSH auth: 

	Filesystem      Size  Used Avail Use% Mounted on
	dev             1.8G     0  1.8G   0% /dev
	run             1.8G  1.6M  1.8G   1% /run
	/dev/sda3       233G  192G   29G  87% /








