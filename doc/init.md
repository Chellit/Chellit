Sample init scripts and service configuration for chellitd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/chellitd.service:    systemd service unit configuration
    contrib/init/chellitd.openrc:     OpenRC compatible SysV style init script
    contrib/init/chellitd.openrcconf: OpenRC conf.d file
    contrib/init/chellitd.conf:       Upstart service configuration file
    contrib/init/chellitd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "chellit" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes chellitd will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, chellitd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, chellitd will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that chellitd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If chellitd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running chellitd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/chellit.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/chellitd`  
Configuration file:  `/etc/chellit/chellit.conf`  
Data directory:      `/var/lib/chellitd`  
PID file:            `/var/run/chellitd/chellitd.pid` (OpenRC and Upstart) or `/var/lib/chellitd/chellitd.pid` (systemd)  
Lock file:           `/var/lock/subsys/chellitd` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the chellit user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
chellit user and group.  Access to chellit-cli and other chellitd rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/chellitd`  
Configuration file:  `~/Library/Application Support/Chellit/chellit.conf`  
Data directory:      `~/Library/Application Support/Chellit`  
Lock file:           `~/Library/Application Support/Chellit/.lock`  

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start chellitd` and to enable for system startup run
`systemctl enable chellitd`

### OpenRC

Rename chellitd.openrc to chellitd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/chellitd start` and configure it to run on startup with
`rc-update add chellitd`

### Upstart (for Debian/Ubuntu based distributions)

Drop chellitd.conf in /etc/init.  Test by running `service chellitd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy chellitd.init to /etc/init.d/chellitd. Test by running `service chellitd start`.

Using this script, you can adjust the path and flags to the chellitd program by
setting the CHELLITD and FLAGS environment variables in the file
/etc/sysconfig/chellitd. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.chellit.chellitd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.chellit.chellitd.plist`.

This Launch Agent will cause chellitd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run chellitd as the current user.
You will need to modify org.chellit.chellitd.plist if you intend to use it as a
Launch Daemon with a dedicated chellit user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
