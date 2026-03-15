#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca {
	extern Settings g_settings;
	struct Settings {
		short m_maxSummaryWidth = 80;
		bool m_tableView = false;
	};
}

#endif