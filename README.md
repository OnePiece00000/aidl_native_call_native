#添加SElinux

1、在 system/sepolicy/prebuilts/api/30.0/private/file_contexts 添加
/system/bin/Myserver          u:object_r:myserver_dt_exec:s0

2、在 system/sepolicy/prebuilts/api/30.0/private/service_contexts 添加
MyService                                 u:object_r:Myserver_service:s0

3、在 system/sepolicy/private/file_contexts 添加
/system/bin/Myserver          u:object_r:myserver_dt_exec:s0

4、在 system/sepolicy/private/service.te
type Myserver_service,              service_manager_type;

5、在 system/sepolicy/private/service_contexts
MyService                                 u:object_r:Myserver_service:s0

6、添加 system/sepolicy/private/myserver.te 文件
type myserver_dt, domain, coredomain;
type myserver_dt_exec, exec_type, file_type, system_file_type;

init_daemon_domain(myserver_dt)

allow myserver_dt servicemanager:binder { call transfer };
allow myserver_dt Myserver_service:service_manager { add find };

binder_use(myserver_dt)
add_service(myserver_dt,Myserver_service)
