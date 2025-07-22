<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="16008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="about" Type="Folder" URL="../about">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="adjustment" Type="Folder" URL="../adjustment">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="axis" Type="Folder" URL="../axis">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="displacement" Type="Folder" URL="../displacement">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="ecu" Type="Folder" URL="../ecu">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="manual" Type="Folder" URL="../manual">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="network" Type="Folder" URL="../network">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="nlc" Type="Folder" URL="../nlc">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="pilotlaser" Type="Folder" URL="../pilotlaser">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="realtime" Type="Folder" URL="../realtime">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="system" Type="Folder" URL="../system">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="TCPHandler" Type="Folder" URL="../TCPHandler">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="update" Type="Folder" URL="../update">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="ex_CorrectErrorChain.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_CorrectErrorChain.vi"/>
				<Item Name="subDisplayMessage.vi" Type="VI" URL="/&lt;vilib&gt;/express/express output/DisplayMessageBlock.llb/subDisplayMessage.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
