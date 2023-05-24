#### AlphaBot MQTT control system for KasperskyOS based on 4diac/Forte   
Project is forked from https://gitflic.ru/project/slavikmai/deep-forte-on-kos-with-fboot repository. The base project used as 4diac forte runtime port layer for KasperskyOS.  
 
System scheme in 4diac IDE:      

![System scheme](https://github.com/ElPallasCat/kos_abot_mqtt/blob/master/Screenshot_1.jpg)
To make 4diac project work, some new blocks were added for Forte runtime:
- AB_COSCMD_RECEIVER - get message by IPC channel from entity with MQTT client. 
- AB_FORWARD - launch AlphaBot's engines. It will be driving forward for the given duration.
- AB_STOP - power off AlphaBot's engines.
- AB_LEFT - launch AlphaBot's engines. It will be driving left for the given duration.
- AB_RIGHT - launch AlphaBot's engines. It will be driving right for the given duration.   

Project include 2 entities:   
- forte.Client - mqtt subscriber with network permissions
- forte.Forte - Forte app for bot control   

Entity stucture:  
![Entity scheme](https://github.com/ElPallasCat/kos_abot_mqtt/blob/master/Screenshot_2.jpg)


#### Prerequisites
Before you begin, ensure that you have met the following requirements:

- You have installed 2.0.1. version of Eclipse 4diac IDE
- You have installed the latest version of KasperskyOS Community Edition
- You have Debian GNU/Linux "Buster" 10.7
#### Usage
To build the example and run the resulting image use the cross-build.sh script.

> Note: *not tested*   

