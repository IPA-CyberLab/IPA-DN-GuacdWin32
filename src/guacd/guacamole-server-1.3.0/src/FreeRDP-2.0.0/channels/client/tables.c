/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Static Entry Point Tables
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 * Copyright 2015 Thincast Technologies GmbH
 * Copyright 2015 DI (FH) Martin Haimberger <martin.haimberger@thincast.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <freerdp/channels/rdpdr.h>
#include "tables.h"

typedef UINT (*static_entry_fkt)();
typedef UINT (*static_addin_fkt)();



extern BOOL VCAPITYPE drdynvc_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE remdesk_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE rdpsnd_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE rdpdr_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE rdp2tcp_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE rail_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE encomsp_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);
extern BOOL VCAPITYPE cliprdr_VirtualChannelEntryEx(PCHANNEL_ENTRY_POINTS,PVOID);

extern UINT video_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT urbdrc_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT rdpsnd_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT rdpgfx_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT rdpei_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT geometry_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT echo_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT disp_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);
extern UINT audin_DVCPluginEntry(IDRDYNVC_ENTRY_POINTS* pEntryPoints);

extern UINT smartcard_DeviceServiceEntry(PDEVICE_SERVICE_ENTRY_POINTS pEntryPoints);
extern UINT serial_DeviceServiceEntry(PDEVICE_SERVICE_ENTRY_POINTS pEntryPoints);
extern UINT printer_DeviceServiceEntry(PDEVICE_SERVICE_ENTRY_POINTS pEntryPoints);
extern UINT parallel_DeviceServiceEntry(PDEVICE_SERVICE_ENTRY_POINTS pEntryPoints);
extern UINT drive_DeviceServiceEntry(PDEVICE_SERVICE_ENTRY_POINTS pEntryPoints);

const STATIC_ENTRY CLIENT_VirtualChannelEntryEx_TABLE[] =
{

	{ "drdynvc", (static_entry_fkt)drdynvc_VirtualChannelEntryEx },
	{ "remdesk", (static_entry_fkt)remdesk_VirtualChannelEntryEx },
	{ "rdpsnd", (static_entry_fkt)rdpsnd_VirtualChannelEntryEx },
	{ "rdpdr", (static_entry_fkt)rdpdr_VirtualChannelEntryEx },
	{ "rdp2tcp", (static_entry_fkt)rdp2tcp_VirtualChannelEntryEx },
	{ "rail", (static_entry_fkt)rail_VirtualChannelEntryEx },
	{ "encomsp", (static_entry_fkt)encomsp_VirtualChannelEntryEx },
	{ "cliprdr", (static_entry_fkt)cliprdr_VirtualChannelEntryEx },
	{ NULL, NULL }
};
const STATIC_ENTRY CLIENT_DVCPluginEntry_TABLE[] =
{

	{ "video", (static_entry_fkt)video_DVCPluginEntry },
	{ "urbdrc", (static_entry_fkt)urbdrc_DVCPluginEntry },
	{ "rdpsnd", (static_entry_fkt)rdpsnd_DVCPluginEntry },
	{ "rdpgfx", (static_entry_fkt)rdpgfx_DVCPluginEntry },
	{ "rdpei", (static_entry_fkt)rdpei_DVCPluginEntry },
	{ "geometry", (static_entry_fkt)geometry_DVCPluginEntry },
	{ "echo", (static_entry_fkt)echo_DVCPluginEntry },
	{ "disp", (static_entry_fkt)disp_DVCPluginEntry },
	{ "audin", (static_entry_fkt)audin_DVCPluginEntry },
	{ NULL, NULL }
};
const STATIC_ENTRY CLIENT_DeviceServiceEntry_TABLE[] =
{

	{ "smartcard", (static_entry_fkt)smartcard_DeviceServiceEntry },
	{ "serial", (static_entry_fkt)serial_DeviceServiceEntry },
	{ "printer", (static_entry_fkt)printer_DeviceServiceEntry },
	{ "parallel", (static_entry_fkt)parallel_DeviceServiceEntry },
	{ "drive", (static_entry_fkt)drive_DeviceServiceEntry },
	{ NULL, NULL }
};

const STATIC_ENTRY_TABLE CLIENT_STATIC_ENTRY_TABLES[] =
{
	{ "VirtualChannelEntryEx", CLIENT_VirtualChannelEntryEx_TABLE },
	{ "DVCPluginEntry", CLIENT_DVCPluginEntry_TABLE },
	{ "DeviceServiceEntry", CLIENT_DeviceServiceEntry_TABLE },
	{ NULL, NULL }
};

extern void libusb_freerdp_urbdrc_client_subsystem_entry(void);
extern void oss_freerdp_rdpsnd_client_subsystem_entry(void);
extern void alsa_freerdp_rdpsnd_client_subsystem_entry(void);
extern void pulse_freerdp_rdpsnd_client_subsystem_entry(void);
extern void fake_freerdp_rdpsnd_client_subsystem_entry(void);
extern void cups_freerdp_printer_client_subsystem_entry(void);
extern void oss_freerdp_audin_client_subsystem_entry(void);
extern void alsa_freerdp_audin_client_subsystem_entry(void);
extern void pulse_freerdp_audin_client_subsystem_entry(void);

const STATIC_SUBSYSTEM_ENTRY CLIENT_DRDYNVC_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_VIDEO_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_URBDRC_SUBSYSTEM_TABLE[] =
{
//	{ "libusb", "", libusb_freerdp_urbdrc_client_subsystem_entry },
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_SMARTCARD_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_SERIAL_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_REMDESK_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPSND_SUBSYSTEM_TABLE[] =
{
	{ "oss", "", oss_freerdp_rdpsnd_client_subsystem_entry },
//	{ "alsa", "", alsa_freerdp_rdpsnd_client_subsystem_entry },
	{ "pulse", "", pulse_freerdp_rdpsnd_client_subsystem_entry },
	{ "fake", "", fake_freerdp_rdpsnd_client_subsystem_entry },
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPGFX_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPEI_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPDR_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDP2TCP_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RAIL_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_PRINTER_SUBSYSTEM_TABLE[] =
{
//	{ "cups", "", cups_freerdp_printer_client_subsystem_entry },
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_PARALLEL_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_GEOMETRY_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_ENCOMSP_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_ECHO_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_DRIVE_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_DISP_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_CLIPRDR_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_AUDIN_SUBSYSTEM_TABLE[] =
{
	{ "oss", "", oss_freerdp_audin_client_subsystem_entry },
//	{ "alsa", "", alsa_freerdp_audin_client_subsystem_entry },
	{ "pulse", "", pulse_freerdp_audin_client_subsystem_entry },
	{ NULL, NULL, NULL }
};
const STATIC_ADDIN_TABLE CLIENT_STATIC_ADDIN_TABLE[] =
{
	{ "drdynvc", "VirtualChannelEntryEx", (static_addin_fkt)drdynvc_VirtualChannelEntryEx, CLIENT_DRDYNVC_SUBSYSTEM_TABLE },
	{ "video", "DVCPluginEntry", (static_addin_fkt)video_DVCPluginEntry, CLIENT_VIDEO_SUBSYSTEM_TABLE },
	{ "urbdrc", "DVCPluginEntry", (static_addin_fkt)urbdrc_DVCPluginEntry, CLIENT_URBDRC_SUBSYSTEM_TABLE },
	{ "smartcard", "DeviceServiceEntry", (static_addin_fkt)smartcard_DeviceServiceEntry, CLIENT_SMARTCARD_SUBSYSTEM_TABLE },
	{ "serial", "DeviceServiceEntry", (static_addin_fkt)serial_DeviceServiceEntry, CLIENT_SERIAL_SUBSYSTEM_TABLE },
	{ "remdesk", "VirtualChannelEntryEx", (static_addin_fkt)remdesk_VirtualChannelEntryEx, CLIENT_REMDESK_SUBSYSTEM_TABLE },
	{ "rdpsnd", "VirtualChannelEntryEx", (static_addin_fkt)rdpsnd_VirtualChannelEntryEx, CLIENT_RDPSND_SUBSYSTEM_TABLE },
	{ "rdpsnd", "DVCPluginEntry", (static_addin_fkt)rdpsnd_DVCPluginEntry, CLIENT_RDPSND_SUBSYSTEM_TABLE },
	{ "rdpgfx", "DVCPluginEntry", (static_addin_fkt)rdpgfx_DVCPluginEntry, CLIENT_RDPGFX_SUBSYSTEM_TABLE },
	{ "rdpei", "DVCPluginEntry", (static_addin_fkt)rdpei_DVCPluginEntry, CLIENT_RDPEI_SUBSYSTEM_TABLE },
	{ "rdpdr", "VirtualChannelEntryEx", (static_addin_fkt)rdpdr_VirtualChannelEntryEx, CLIENT_RDPDR_SUBSYSTEM_TABLE },
	{ "rdp2tcp", "VirtualChannelEntryEx", (static_addin_fkt)rdp2tcp_VirtualChannelEntryEx, CLIENT_RDP2TCP_SUBSYSTEM_TABLE },
	{ "rail", "VirtualChannelEntryEx", (static_addin_fkt)rail_VirtualChannelEntryEx, CLIENT_RAIL_SUBSYSTEM_TABLE },
	{ "printer", "DeviceServiceEntry", (static_addin_fkt)printer_DeviceServiceEntry, CLIENT_PRINTER_SUBSYSTEM_TABLE },
	{ "parallel", "DeviceServiceEntry", (static_addin_fkt)parallel_DeviceServiceEntry, CLIENT_PARALLEL_SUBSYSTEM_TABLE },
	{ "geometry", "DVCPluginEntry", (static_addin_fkt)geometry_DVCPluginEntry, CLIENT_GEOMETRY_SUBSYSTEM_TABLE },
	{ "encomsp", "VirtualChannelEntryEx", (static_addin_fkt)encomsp_VirtualChannelEntryEx, CLIENT_ENCOMSP_SUBSYSTEM_TABLE },
	{ "echo", "DVCPluginEntry", (static_addin_fkt)echo_DVCPluginEntry, CLIENT_ECHO_SUBSYSTEM_TABLE },
	{ "drive", "DeviceServiceEntry", (static_addin_fkt)drive_DeviceServiceEntry, CLIENT_DRIVE_SUBSYSTEM_TABLE },
	{ "disp", "DVCPluginEntry", (static_addin_fkt)disp_DVCPluginEntry, CLIENT_DISP_SUBSYSTEM_TABLE },
	{ "cliprdr", "VirtualChannelEntryEx", (static_addin_fkt)cliprdr_VirtualChannelEntryEx, CLIENT_CLIPRDR_SUBSYSTEM_TABLE },
	{ "audin", "DVCPluginEntry", (static_addin_fkt)audin_DVCPluginEntry, CLIENT_AUDIN_SUBSYSTEM_TABLE },
	{ NULL, NULL, NULL, NULL }
};

