**Create VM and Get External IP**

Step 1: Create a VM

Open Compute Engine – VM Instances

First, check that the correct project is selected at the top of the page and that no filters are hiding instances.

If the list is still empty, click Create Instance.


Settings:

Machine Series - E2

Machine Type: e2-micro

OS: Debain Linux

External IPv4 address: Ephemeral


Step 2: Get the external IP

After creating the instance, the VM list will be visible.

You can open VM from Connect:SSH.



** Open the Port in GCP Firewall**

Go to the VPC network page in the Google Cloud Console.

In the left menu, click Firewall.

Click + Create Firewall Rule at the top.

Configure the rule with the following parameters:

Name: allow-socket-traffic (any name is fine)

Network: default (or your specific VPC network)

Direction of traffic: Ingress

Action on match: Allow

Targets: All instances in the network (or specify a target tag if you want it limited to one VM)

Source filter: IPv4 ranges

Source IPv4 ranges: 0.0.0.0/0 (Note: This allows traffic from any computer on the internet. For security, you can change this to your specific home/office public IP).

Protocols and ports: Check Specified protocols and ports, select TCP (or UDP depending on your socket type), and enter your port number (e.g., 8080).

Click Create



** Run the server on GCP**

1. Open the GCP VM

Go to:

Google Cloud Console → Compute Engine → VM instances → SSH

3. Install GCC if necessary

sudo apt update

sudo apt install -y gcc

Verify: gcc --version

** Verify VM (IP and Port)**

1. From your laptop: ping IP (example: ping 34.10.30.217)
2. Troubleshooting: Run in GCP VM SSH terminal to check the port: 
	sudo ss -ltnp | grep ':5000’

	sudo ufw status (if active, then)

	sudo ufw allow 5000/tcp

Open the VM details: Compute Engine → VM instances → Click the VM → Edit

Under Network tags, add: socket-server

Save the VM. (Stop VM when not using to save credits. IP will change.)

4. Run a program using port 5000 (or any), then run from laptop: 
	Test-NetConnection 34.10.30.217 -Port 5000

Alternate: Run a second GCP Virtual Machine as the Client



