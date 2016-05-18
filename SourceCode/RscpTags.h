#ifndef RSCP_TAGS_H_
#define RSCP_TAGS_H_

#define TAG_RSCP_REQ_AUTHENTICATION                         	0x00000001
#define TAG_RSCP_AUTHENTICATION_USER                        	0x00000002
#define TAG_RSCP_AUTHENTICATION_PASSWORD                    	0x00000003
#define TAG_RSCP_AUTHENTICATION                             	0x00800001
#define TAG_RSCP_REQ_USER_LEVEL                             	0x00000004
#define TAG_RSCP_USER_LEVEL                                 	0x00800004
#define TAG_RSCP_REQ_SET_ENCRYPTION_PASSPHRASE              	0x00000005
#define TAG_RSCP_SET_ENCRYPTION_PASSPHRASE                  	0x00800005
#define TAG_RSCP_GENERAL_ERROR                              	0x00FFFFFF


#define TAG_EMS_REQ_POWER_PV                                	0x01000001
#define TAG_EMS_REQ_POWER_BAT                               	0x01000002
#define TAG_EMS_REQ_POWER_HOME                              	0x01000003
#define TAG_EMS_REQ_POWER_GRID                              	0x01000004
#define TAG_EMS_REQ_POWER_ADD                               	0x01000005
#define TAG_EMS_REQ_AUTARKY                                 	0x01000006
#define TAG_EMS_REQ_SELF_CONSUMPTION                        	0x01000007
#define TAG_EMS_REQ_BAT_SOC                                 	0x01000008
#define TAG_EMS_REQ_COUPLING_MODE                           	0x01000009
#define TAG_EMS_REQ_STORED_ERRORS                           	0x0100000A
#define TAG_EMS_REQ_MODE                                    	0x01000011
#define TAG_EMS_REQ_BALANCED_PHASES                         	0x01000012
#define TAG_EMS_REQ_INSTALLED_PEAK_POWER                    	0x01000013
#define TAG_EMS_REQ_DERATE_AT_PERCENT_VALUE                 	0x01000014
#define TAG_EMS_REQ_DERATE_AT_POWER_VALUE                   	0x01000015
#define TAG_EMS_REQ_ERROR_BUZZER_ENABLED                    	0x01000016
#define TAG_EMS_REQ_SET_BALANCED_PHASES                     	0x01000017
#define TAG_EMS_REQ_SET_INSTALLED_PEAK_POWER                	0x01000018
#define TAG_EMS_REQ_SET_DERATE_PERCENT                      	0x01000019
#define TAG_EMS_REQ_SET_ERROR_BUZZER_ENABLED                	0x0100001A
#define TAG_EMS_REQ_START_ADJUST_BATTERY_VOLTAGE            	0x0100001B
#define TAG_EMS_REQ_CANCEL_ADJUST_BATTERY_VOLTAGE           	0x0100001C
#define TAG_EMS_REQ_ADJUST_BATTERY_VOLTAGE_STATUS           	0x0100001D
#define TAG_EMS_REQ_CONFIRM_ERRORS                          	0x0100001E
#define TAG_EMS_REQ_POWER_WB_ALL                            	0x0100001F
#define TAG_EMS_REQ_POWER_WB_SOLAR                          	0x01000020
#define TAG_EMS_REQ_EXT_SRC_AVAILABLE                       	0x01000021


#define TAG_EMS_POWER_PV                                    	0x01800001
#define TAG_EMS_POWER_BAT                                   	0x01800002
#define TAG_EMS_POWER_HOME                                  	0x01800003
#define TAG_EMS_POWER_GRID                                  	0x01800004
#define TAG_EMS_POWER_ADD                                   	0x01800005
#define TAG_EMS_AUTARKY                                     	0x01800006
#define TAG_EMS_SELF_CONSUMPTION                            	0x01800007
#define TAG_EMS_BAT_SOC                                     	0x01800008
#define TAG_EMS_COUPLING_MODE                               	0x01800009
#define TAG_EMS_STORED_ERRORS                               	0x0180000A
#define TAG_EMS_ERROR_CONTAINER                             	0x0180000B
#define TAG_EMS_ERROR_TYPE                                  	0x0180000C
#define TAG_EMS_ERROR_SOURCE                                	0x0180000D
#define TAG_EMS_ERROR_MESSAGE                               	0x0180000E
#define TAG_EMS_ERROR_CODE                                  	0x0180000F
#define TAG_EMS_ERROR_TIMESTAMP                             	0x01800010
#define TAG_EMS_MODE                                        	0x01800011
#define TAG_EMS_BALANCED_PHASES                             	0x01800012
#define TAG_EMS_INSTALLED_PEAK_POWER                        	0x01800013
#define TAG_EMS_DERATE_AT_PERCENT_VALUE                     	0x01800014
#define TAG_EMS_DERATE_AT_POWER_VALUE                       	0x01800015
#define TAG_EMS_ERROR_BUZZER_ENABLED                        	0x01800016
#define TAG_EMS_SET_BALANCED_PHASES                         	0x01800017
#define TAG_EMS_SET_INSTALLED_PEAK_POWER                    	0x01800018
#define TAG_EMS_SET_DERATE_PERCENT                          	0x01800019
#define TAG_EMS_SET_ERROR_BUZZER_ENABLED                    	0x0180001A
#define TAG_EMS_START_ADJUST_BATTERY_VOLTAGE                	0x0180001B
#define TAG_EMS_CANCEL_ADJUST_BATTERY_VOLTAGE               	0x0180001C
#define TAG_EMS_ADJUST_BATTERY_VOLTAGE_STATUS               	0x0180001D
#define TAG_EMS_CONFIRM_ERRORS                              	0x0180001E
#define TAG_EMS_POWER_WB_ALL                                	0x0180001F
#define TAG_EMS_POWER_WB_SOLAR                              	0x01800020
#define TAG_EMS_EXT_SRC_AVAILABLE                           	0x01800021


#define TAG_EMS_REQ_SET_POWER                               	0x01000030
#define TAG_EMS_REQ_SET_POWER_MODE                          	0x01000031
#define TAG_EMS_REQ_SET_POWER_VALUE                         	0x01000032
#define TAG_EMS_SET_POWER                                   	0x01800030
#define TAG_EMS_REQ_STATUS                                  	0x01000040
#define TAG_EMS_STATUS                                      	0x01800040
#define TAG_EMS_REQ_USED_CHARGE_LIMIT                       	0x01000041
#define TAG_EMS_REQ_BAT_CHARGE_LIMIT                        	0x01000042
#define TAG_EMS_REQ_DCDC_CHARGE_LIMIT                       	0x01000043
#define TAG_EMS_REQ_USER_CHARGE_LIMIT                       	0x01000044
#define TAG_EMS_REQ_USED_DISCHARGE_LIMIT                    	0x01000045
#define TAG_EMS_REQ_BAT_DISCHARGE_LIMIT                     	0x01000046
#define TAG_EMS_REQ_DCDC_DISCHARGE_LIMIT                    	0x01000047
#define TAG_EMS_REQ_USER_DISCHARGE_LIMIT                    	0x01000048
#define TAG_EMS_USED_CHARGE_LIMIT                           	0x01800041
#define TAG_EMS_BAT_CHARGE_LIMIT                            	0x01800042
#define TAG_EMS_DCDC_CHARGE_LIMIT                           	0x01800043
#define TAG_EMS_USER_CHARGE_LIMIT                           	0x01800044
#define TAG_EMS_USED_DISCHARGE_LIMIT                        	0x01800045
#define TAG_EMS_BAT_DISCHARGE_LIMIT                         	0x01800046
#define TAG_EMS_DCDC_DISCHARGE_LIMIT                        	0x01800047
#define TAG_EMS_USER_DISCHARGE_LIMIT                        	0x01800048
#define TAG_EMS_REQ_SET_POWER_CONTROL_OFFSET                	0x01000060
#define TAG_EMS_SET_POWER_CONTROL_OFFSET                    	0x01800060
#define TAG_EMS_REQ_REMAINING_BAT_CHARGE_POWER              	0x01000071
#define TAG_EMS_REMAINING_BAT_CHARGE_POWER                  	0x01800071
#define TAG_EMS_REQ_REMAINING_BAT_DISCHARGE_POWER           	0x01000072
#define TAG_EMS_REMAINING_BAT_DISCHARGE_POWER               	0x01800072
#define TAG_EMS_REQ_EMERGENCY_POWER_STATUS                  	0x01000073
#define TAG_EMS_EMERGENCY_POWER_STATUS                      	0x01800073
#define TAG_EMS_REQ_SET_EMERGENCY_POWER                     	0x01000074
#define TAG_EMS_SET_EMERGENCY_POWER                         	0x01800074
#define TAG_EMS_REQ_SET_OVERRIDE_AVAILABLE_POWER            	0x01000075
#define TAG_EMS_SET_OVERRIDE_AVAILABLE_POWER                	0x01800075

#define TAG_EMS_SET_BATTERY_TO_CAR_MODE                     	0x01800076
#define TAG_EMS_REQ_SET_BATTERY_TO_CAR_MODE                 	0x01000076
#define TAG_EMS_BATTERY_TO_CAR_MODE                         	0x01800077
#define TAG_EMS_REQ_BATTERY_TO_CAR_MODE                     	0x01000077
#define TAG_EMS_SET_BATTERY_BEFORE_CAR_MODE                 	0x01800078
#define TAG_EMS_REQ_SET_BATTERY_BEFORE_CAR_MODE             	0x01000078
#define TAG_EMS_BATTERY_BEFORE_CAR_MODE                     	0x01800079
#define TAG_EMS_REQ_BATTERY_BEFORE_CAR_MODE                 	0x01000079

#define TAG_EMS_REQ_GET_IDLE_PERIODS                        	0x01000080
#define TAG_EMS_GET_IDLE_PERIODS                            	0x01800080
#define TAG_EMS_REQ_SET_IDLE_PERIODS                        	0x01000081
#define TAG_EMS_SET_IDLE_PERIODS                            	0x01800081
#define TAG_EMS_IDLE_PERIOD                                 	0x01000082
#define TAG_EMS_IDLE_PERIOD_TYPE                            	0x01000083
#define TAG_EMS_IDLE_PERIOD_DAY                             	0x01000084
#define TAG_EMS_IDLE_PERIOD_START                           	0x01000085
#define TAG_EMS_IDLE_PERIOD_END                             	0x01000086
#define TAG_EMS_IDLE_PERIOD_HOUR                            	0x01000087
#define TAG_EMS_IDLE_PERIOD_MINUTE                          	0x01000088
#define TAG_EMS_IDLE_PERIOD_ACTIVE                          	0x01000089
#define TAG_EMS_REQ_IDLE_PERIOD_CHANGE_MARKER               	0x0100008A
#define TAG_EMS_IDLE_PERIOD_CHANGE_MARKER                   	0x0180008A

#define TAG_EMS_REQ_GET_POWER_SETTINGS                      	0x0100008B
#define TAG_EMS_GET_POWER_SETTINGS                          	0x0180008B
#define TAG_EMS_REQ_SET_POWER_SETTINGS                      	0x0100008C
#define TAG_EMS_SET_POWER_SETTINGS                          	0x0180008C
#define TAG_EMS_POWER_LIMITS_USED                           	0x01000100
#define TAG_EMS_RES_POWER_LIMITS_USED                       	0x01800100
#define TAG_EMS_MAX_CHARGE_POWER                            	0x01000101
#define TAG_EMS_RES_MAX_CHARGE_POWER                        	0x01800101
#define TAG_EMS_MAX_DISCHARGE_POWER                         	0x01000102
#define TAG_EMS_RES_MAX_DISCHARGE_POWER                     	0x01800102
#define TAG_EMS_DISCHARGE_START_POWER                       	0x01000103
#define TAG_EMS_RES_DISCHARGE_START_POWER                   	0x01800103
#define TAG_EMS_POWERSAVE_ENABLED                           	0x01000104
#define TAG_EMS_RES_POWERSAVE_ENABLED                       	0x01800104
#define TAG_EMS_WEATHER_REGULATED_CHARGE_ENABLED            	0x01000105
#define TAG_EMS_RES_WEATHER_REGULATED_CHARGE_ENABLED        	0x01800105

#define TAG_EMS_REQ_SETTINGS_CHANGE_MARKER                  	0x0100008D
#define TAG_EMS_SETTINGS_CHANGE_MARKER                      	0x0180008D

#define TAG_EMS_REQ_GET_MANUAL_CHARGE                       	0x0100008E
#define TAG_EMS_GET_MANUAL_CHARGE                           	0x0180008E
#define TAG_EMS_MANUAL_CHARGE_START_COUNTER                 	0x01000150
#define TAG_EMS_MANUAL_CHARGE_ACTIVE                        	0x01000151
#define TAG_EMS_MANUAL_CHARGE_ENERGY_COUNTER                	0x01000152
#define TAG_EMS_MANUAL_CHARGE_LASTSTART                     	0x01000153
#define TAG_EMS_REQ_START_MANUAL_CHARGE                     	0x0100008F
#define TAG_EMS_START_MANUAL_CHARGE                         	0x0180008F

#define TAG_EMS_REQ_START_EMERGENCYPOWER_TEST               	0x01000090
#define TAG_EMS_START_EMERGENCYPOWER_TEST                   	0x01800090

#define TAG_EMS_REQ_GET_GENERATOR_STATE                     	0x01000091
#define TAG_EMS_GET_GENERATOR_STATE                         	0x01800091
#define TAG_EMS_REQ_SET_GENERATOR_MODE                      	0x01000092
#define TAG_EMS_SET_GENERATOR_MODE                          	0x01800092

#define TAG_EMS_REQ_EMERGENCYPOWER_TEST_STATUS              	0x01000093
#define TAG_EMS_EMERGENCYPOWER_TEST_STATUS                  	0x01800093
#define TAG_EMS_EPTEST_NEXT_TESTSTART                       	0x01000094
#define TAG_EMS_EPTEST_START_COUNTER                        	0x01000095
#define TAG_EMS_EPTEST_RUNNING                              	0x01000096

#define TAG_EMS_REQ_GET_SYS_SPECS                           	0x01000097
#define TAG_EMS_GET_SYS_SPECS                               	0x01800098
#define TAG_EMS_SYS_SPEC                                    	0x01000099
#define TAG_EMS_SYS_SPEC_INDEX                              	0x0100009A
#define TAG_EMS_SYS_SPEC_NAME                               	0x0100009B
#define TAG_EMS_SYS_SPEC_VALUE_INT                          	0x0100009C
#define TAG_EMS_SYS_SPEC_VALUE_STRING                       	0x0100009D







#define TAG_EMS_REQ_ALIVE                                   	0x01050000
#define TAG_EMS_ALIVE                                       	0x01850000
#define TAG_EMS_GENERAL_ERROR                               	0x01FFFFFF


#define TAG_BAT_REQ_DATA                                    	0x03040000
#define TAG_BAT_INDEX                                       	0x03040001
#define TAG_BAT_DATA                                        	0x03840000
#define TAG_BAT_RSOC                                        	0x03800001
#define TAG_BAT_MODULE_VOLTAGE                              	0x03800002
#define TAG_BAT_CURRENT                                     	0x03800003
#define TAG_BAT_MAX_BAT_VOLTAGE                             	0x03800004
#define TAG_BAT_MAX_CHARGE_CURRENT                          	0x03800005
#define TAG_BAT_EOD_VOLTAGE                                 	0x03800006
#define TAG_BAT_MAX_DISCHARGE_CURRENT                       	0x03800007
#define TAG_BAT_CHARGE_CYCLES                               	0x03800008
#define TAG_BAT_TERMINAL_VOLTAGE                            	0x03800009
#define TAG_BAT_STATUS_CODE                                 	0x0380000A
#define TAG_BAT_ERROR_CODE                                  	0x0380000B
#define TAG_BAT_DEVICE_NAME                                 	0x0380000C
#define TAG_BAT_DCB_COUNT                                   	0x0380000D
#define TAG_BAT_RSOC_REAL                                   	0x0380000E
#define TAG_BAT_ASOC                                        	0x0380000F
#define TAG_BAT_FCC                                         	0x03800010
#define TAG_BAT_RC                                          	0x03800011
#define TAG_BAT_MAX_DCB_CELL_CURRENT                        	0x03800012
#define TAG_BAT_MIN_DCB_CELL_CURRENT                        	0x03800013
#define TAG_BAT_MAX_DCB_CELL_VOLTAGE                        	0x03800014
#define TAG_BAT_MIN_DCB_CELL_VOLTAGE                        	0x03800015
#define TAG_BAT_MAX_DCB_CELL_TEMPERATURE                    	0x03800016
#define TAG_BAT_MIN_DCB_CELL_TEMPERATURE                    	0x03800017
#define TAG_BAT_DCB_ALL_CELL_TEMPERATURES                   	0x03800018
#define TAG_BAT_DCB_CELL_TEMPERATURE                        	0x03800019
#define TAG_BAT_DCB_ALL_CELL_VOLTAGES                       	0x0380001A
#define TAG_BAT_DCB_CELL_VOLTAGE                            	0x0380001B
#define TAG_BAT_OPEN_BREAKER                                	0x0380001C
#define TAG_BAT_OPEN_BREAKER_CONFIRM                        	0x0380001D
#define TAG_BAT_READY_FOR_SHUTDOWN                          	0x0380001E
#define TAG_BAT_FIRMWARE_VERSION                            	0x0380001F
#define TAG_BAT_TIME_LAST_RESPONSE                          	0x03800024
#define TAG_BAT_MANUFACTURER_NAME                           	0x03800025
#define TAG_BAT_USABLE_CAPACITY                             	0x03800026
#define TAG_BAT_USABLE_REMAINING_CAPACITY                   	0x03800027
#define TAG_BAT_INFO                                        	0x03800020
#define TAG_BAT_TRAINING_MODE                               	0x03800021
#define TAG_BAT_UPDATE_STATUS                               	0x03800022
#define TAG_BAT_SET_A1_DATA                                 	0x03800028
#define TAG_BAT_CONTROL_CODE                                	0x03800032
#define TAG_BAT_REQ_RSOC                                    	0x03000001
#define TAG_BAT_REQ_MODULE_VOLTAGE                          	0x03000002
#define TAG_BAT_REQ_CURRENT                                 	0x03000003
#define TAG_BAT_REQ_MAX_BAT_VOLTAGE                         	0x03000004
#define TAG_BAT_REQ_MAX_CHARGE_CURRENT                      	0x03000005
#define TAG_BAT_REQ_EOD_VOLTAGE                             	0x03000006
#define TAG_BAT_REQ_MAX_DISCHARGE_CURRENT                   	0x03000007
#define TAG_BAT_REQ_CHARGE_CYCLES                           	0x03000008
#define TAG_BAT_REQ_TERMINAL_VOLTAGE                        	0x03000009
#define TAG_BAT_REQ_STATUS_CODE                             	0x0300000A
#define TAG_BAT_REQ_ERROR_CODE                              	0x0300000B
#define TAG_BAT_REQ_DEVICE_NAME                             	0x0300000C
#define TAG_BAT_REQ_DCB_COUNT                               	0x0300000D
#define TAG_BAT_REQ_RSOC_REAL                               	0x0300000E
#define TAG_BAT_REQ_ASOC                                    	0x0300000F
#define TAG_BAT_REQ_FCC                                     	0x03000010
#define TAG_BAT_REQ_RC                                      	0x03000011
#define TAG_BAT_REQ_MAX_DCB_CELL_CURRENT                    	0x03000012
#define TAG_BAT_REQ_MIN_DCB_CELL_CURRENT                    	0x03000013
#define TAG_BAT_REQ_MAX_DCB_CELL_VOLTAGE                    	0x03000014
#define TAG_BAT_REQ_MIN_DCB_CELL_VOLTAGE                    	0x03000015
#define TAG_BAT_REQ_MAX_DCB_CELL_TEMPERATURE                	0x03000016
#define TAG_BAT_REQ_MIN_DCB_CELL_TEMPERATURE                	0x03000017
#define TAG_BAT_REQ_DCB_ALL_CELL_TEMPERATURES               	0x03000018
#define TAG_BAT_REQ_DCB_ALL_CELL_VOLTAGES                   	0x0300001A
#define TAG_BAT_REQ_OPEN_BREAKER                            	0x0300001C
#define TAG_BAT_REQ_OPEN_BREAKER_CONFIRM                    	0x0300001D
#define TAG_BAT_REQ_READY_FOR_SHUTDOWN                      	0x0300001E
#define TAG_BAT_REQ_FIRMWARE_VERSION                        	0x0300001F
#define TAG_BAT_REQ_INFO                                    	0x03000020
#define TAG_BAT_REQ_TRAINING_MODE                           	0x03000021
#define TAG_BAT_REQ_UPDATE_STATUS                           	0x03000022
#define TAG_BAT_REQ_SET_TRAINING_MODE                       	0x03000023
#define TAG_BAT_REQ_TIME_LAST_RESPONSE                      	0x03000024
#define TAG_BAT_REQ_MANUFACTURER_NAME                       	0x03000025
#define TAG_BAT_REQ_USABLE_CAPACITY                         	0x03000026
#define TAG_BAT_REQ_USABLE_REMAINING_CAPACITY               	0x03000027
#define TAG_BAT_REQ_SET_A1_DATA                             	0x03000028
#define TAG_BAT_REQ_SET_A1_MODE                             	0x03000029
#define TAG_BAT_REQ_SET_A1_VOLTAGE                          	0x03000030
#define TAG_BAT_REQ_SET_A1_CURRENT                          	0x03000031
#define TAG_BAT_REQ_CONTROL_CODE                            	0x03000032
#define TAG_BAT_REQ_DCB_INFO                                	0x03000042
#define TAG_BAT_DCB_INFO                                    	0x03800042
#define TAG_BAT_DCB_INDEX                                   	0x03800100
#define TAG_BAT_DCB_LAST_MESSAGE_TIMESTAMP                  	0x03800101
#define TAG_BAT_DCB_MAX_CHARGE_VOLTAGE                      	0x03800102
#define TAG_BAT_DCB_MAX_CHARGE_CURRENT                      	0x03800103
#define TAG_BAT_DCB_END_OF_DISCHARGE                        	0x03800104
#define TAG_BAT_DCB_MAX_DISCHARGE_CURRENT                   	0x03800105
#define TAG_BAT_DCB_FULL_CHARGE_CAPACITY                    	0x03800106
#define TAG_BAT_DCB_REMAINING_CAPACITY                      	0x03800107
#define TAG_BAT_DCB_SOC                                     	0x03800108
#define TAG_BAT_DCB_SOH                                     	0x03800109
#define TAG_BAT_DCB_CYCLE_COUNT                             	0x03800110
#define TAG_BAT_DCB_CURRENT                                 	0x03800111
#define TAG_BAT_DCB_VOLTAGE                                 	0x03800112
#define TAG_BAT_DCB_CURRENT_AVG_30S                         	0x03800113
#define TAG_BAT_DCB_VOLTAGE_AVG_30S                         	0x03800114
#define TAG_BAT_DCB_DESIGN_CAPACITY                         	0x03800115
#define TAG_BAT_DCB_DESIGN_VOLTAGE                          	0x03800116
#define TAG_BAT_DCB_CHARGE_LOW_TEMPERATURE                  	0x03800117
#define TAG_BAT_DCB_CHARGE_HIGH_TEMPERATURE                 	0x03800118
#define TAG_BAT_DCB_MANUFACTURE_DATE                        	0x03800119
#define TAG_BAT_DCB_SERIALNO                                	0x03800120
#define TAG_BAT_DCB_PROTOCOL_VERSION                        	0x03800121
#define TAG_BAT_DCB_FW_VERSION                              	0x03800122
#define TAG_BAT_DCB_DATA_TABLE_VERSION                      	0x03800123
#define TAG_BAT_DCB_PCB_VERSION                             	0x03800124

#define TAG_BAT_REQ_DEVICE_STATE                            	0x03060000
#define TAG_BAT_DEVICE_STATE                                	0x03860000
#define TAG_BAT_DEVICE_CONNECTED                            	0x03860001
#define TAG_BAT_DEVICE_WORKING                              	0x03860002
#define TAG_BAT_DEVICE_IN_SERVICE                           	0x03860003
#define TAG_BAT_GENERAL_ERROR                               	0x03FFFFFF

#define TAG_PM_REQ_DATA                                     	0x05040000
#define TAG_PM_INDEX                                        	0x05040001
#define TAG_PM_DATA                                         	0x05840000
#define TAG_PM_REQ_POWER_L1                                 	0x05000001
#define TAG_PM_REQ_POWER_L2                                 	0x05000002
#define TAG_PM_REQ_POWER_L3                                 	0x05000003
#define TAG_PM_REQ_ACTIVE_PHASES                            	0x05000004
#define TAG_PM_REQ_MODE                                     	0x05000005
#define TAG_PM_REQ_ENERGY_L1                                	0x05000006
#define TAG_PM_REQ_ENERGY_L2                                	0x05000007
#define TAG_PM_REQ_ENERGY_L3                                	0x05000008
#define TAG_PM_REQ_DEVICE_ID                                	0x05000009
#define TAG_PM_REQ_ERROR_CODE                               	0x0500000A
#define TAG_PM_REQ_SET_PHASE_ELIMINATION                    	0x0500000B
#define TAG_PM_REQ_GET_PHASE_ELIMINATION                    	0x05000018
#define TAG_PM_REQ_FIRMWARE_VERSION                         	0x0500000C
#define TAG_PM_REQ_SET_FOR_EMERGENCY_TEST                   	0x0500000D
#define TAG_PM_REQ_IS_CAN_SILENCE                           	0x0500000E

#define TAG_PM_REQ_VOLTAGE_L1                               	0x05000011
#define TAG_PM_REQ_VOLTAGE_L2                               	0x05000012
#define TAG_PM_REQ_VOLTAGE_L3                               	0x05000013
#define TAG_PM_REQ_TYPE                                     	0x05000014

#define TAG_PM_POWER_L1                                     	0x05800001
#define TAG_PM_POWER_L2                                     	0x05800002
#define TAG_PM_POWER_L3                                     	0x05800003
#define TAG_PM_ACTIVE_PHASES                                	0x05800004
#define TAG_PM_MODE                                         	0x05800005
#define TAG_PM_ENERGY_L1                                    	0x05800006
#define TAG_PM_ENERGY_L2                                    	0x05800007
#define TAG_PM_ENERGY_L3                                    	0x05800008
#define TAG_PM_DEVICE_ID                                    	0x05800009
#define TAG_PM_ERROR_CODE                                   	0x0580000A
#define TAG_PM_SET_PHASE_ELIMINATION                        	0x0580000B
#define TAG_PM_GET_PHASE_ELIMINATION                        	0x05800018
#define TAG_PM_FIRMWARE_VERSION                             	0x0580000C
#define TAG_PM_SET_FOR_EMERGENCY_TEST                       	0x0580000D
#define TAG_PM_IS_CAN_SILENCE                               	0x0580000E

#define TAG_PM_VOLTAGE_L1                                   	0x05800011
#define TAG_PM_VOLTAGE_L2                                   	0x05800012
#define TAG_PM_VOLTAGE_L3                                   	0x05800013
#define TAG_PM_TYPE                                         	0x05800014

#define TAG_PM_REQ_COMM_STATE                               	0x05000050
#define TAG_PM_COMM_STATE                                   	0x05800050
#define TAG_PM_CS_START_TIME                                	0x05800051
#define TAG_PM_CS_LAST_TIME                                 	0x05800052
#define TAG_PM_CS_SUCC_FRAMES_ALL                           	0x05800053
#define TAG_PM_CS_SUCC_FRAMES_100                           	0x05800054
#define TAG_PM_CS_EXP_FRAMES_ALL                            	0x05800055
#define TAG_PM_CS_EXP_FRAMES_100                            	0x05800056
#define TAG_PM_CS_ERR_FRAMES_ALL                            	0x05800057
#define TAG_PM_CS_ERR_FRAMES_100                            	0x05800058
#define TAG_PM_CS_UNK_FRAMES                                	0x05800059
#define TAG_PM_CS_ERR_FRAME                                 	0x0580005A


#define TAG_PM_REQ_DEVICE_STATE                             	0x05060000
#define TAG_PM_DEVICE_STATE                                 	0x05860000
#define TAG_PM_DEVICE_CONNECTED                             	0x05860001
#define TAG_PM_DEVICE_WORKING                               	0x05860002
#define TAG_PM_DEVICE_IN_SERVICE                            	0x05860003
#define TAG_PM_GENERAL_ERROR                                	0x05FFFFFF



#define TAG_DCDC_REQ_DATA                                   	0x04040000
#define TAG_DCDC_INDEX                                      	0x04040001
#define TAG_DCDC_DATA                                       	0x04840000
#define TAG_DCDC_REQ_I_BAT                                  	0x04000001
#define TAG_DCDC_REQ_U_BAT                                  	0x04000002
#define TAG_DCDC_REQ_P_BAT                                  	0x04000003
#define TAG_DCDC_REQ_I_DCL                                  	0x04000004
#define TAG_DCDC_REQ_U_DCL                                  	0x04000005
#define TAG_DCDC_REQ_P_DCL                                  	0x04000006
#define TAG_DCDC_REQ_SELF_TEST                              	0x04000007
#define TAG_DCDC_REQ_FIRMWARE_VERSION                       	0x04000008
#define TAG_DCDC_REQ_FPGA_FIRMWARE                          	0x04000009
#define TAG_DCDC_REQ_SERIAL_NUMBER                          	0x0400000A
#define TAG_DCDC_REQ_BOARD_VERSION                          	0x0400000B
#define TAG_DCDC_REQ_FLASH_FILE_LIST                        	0x0400000C
#define TAG_DCDC_REQ_IS_FLASHING                            	0x0400000E
#define TAG_DCDC_REQ_FLASH                                  	0x0400000F
#define TAG_DCDC_REQ_STATUS                                 	0x04000010
#define TAG_DCDC_REQ_STATUS_AS_STRING                       	0x04000013

#define TAG_DCDC_I_BAT                                      	0x04800001
#define TAG_DCDC_U_BAT                                      	0x04800002
#define TAG_DCDC_P_BAT                                      	0x04800003
#define TAG_DCDC_I_DCL                                      	0x04800004
#define TAG_DCDC_U_DCL                                      	0x04800005
#define TAG_DCDC_P_DCL                                      	0x04800006
#define TAG_DCDC_SELF_TEST                                  	0x04800007
#define TAG_DCDC_FIRMWARE_VERSION                           	0x04800008
#define TAG_DCDC_FPGA_FIRMWARE                              	0x04800009
#define TAG_DCDC_SERIAL_NUMBER                              	0x0480000A
#define TAG_DCDC_BOARD_VERSION                              	0x0480000B
#define TAG_DCDC_FLASH_FILE_LIST                            	0x0480000C
#define TAG_DCDC_FLASH_FILE                                 	0x0480000D
#define TAG_DCDC_IS_FLASHING                                	0x0480000E
#define TAG_DCDC_FLASH                                      	0x0480000F
#define TAG_DCDC_STATUS                                     	0x04800010
#define TAG_DCDC_STATE                                      	0x04800011
#define TAG_DCDC_SUBSTATE                                   	0x04800012
#define TAG_DCDC_STATUS_AS_STRING                           	0x04800013
#define TAG_DCDC_STATE_AS_STRING                            	0x04800014
#define TAG_DCDC_SUBSTATE_AS_STRING                         	0x04800015

#define TAG_DCDC_REQ_DEVICE_STATE                           	0x04060000
#define TAG_DCDC_DEVICE_STATE                               	0x04860000
#define TAG_DCDC_DEVICE_CONNECTED                           	0x04860001
#define TAG_DCDC_DEVICE_WORKING                             	0x04860002
#define TAG_DCDC_DEVICE_IN_SERVICE                          	0x04860003
#define TAG_DCDC_GENERAL_ERROR                              	0x04FFFFFF

#define TAG_PVI_DATA                                        	0x02840000
#define TAG_PVI_REQ_DATA                                    	0x02040000
#define TAG_PVI_INDEX                                       	0x02040001



#define TAG_PVI_VALUE                                       	0x02040005

#define TAG_PVI_GENERAL_ERROR                               	0x02FFFFFF

#define TAG_PVI_ON_GRID                                     	0x02800001
#define TAG_PVI_REQ_ON_GRID                                 	0x02000001
#define TAG_PVI_STATE                                       	0x02800002
#define TAG_PVI_REQ_STATE                                   	0x02000002
#define TAG_PVI_LAST_ERROR                                  	0x02800003
#define TAG_PVI_REQ_LAST_ERROR                              	0x02000003
#define TAG_PVI_IS_FLASHING                                 	0x02800004
#define TAG_PVI_REQ_IS_FLASHING                             	0x02000004
#define TAG_PVI_REQ_START_FLASHING                          	0x02000005
#define TAG_PVI_FLASH_FILE_LIST                             	0x02800006
#define TAG_PVI_FLASH_FILE                                  	0x02800007
#define TAG_PVI_REQ_FLASH_FILE_LIST                         	0x02000006
#define TAG_PVI_SERVICE_PROGRESS_STATE                      	0x02800008
#define TAG_PVI_REQ_SERVICE_PROGRESS_STATE                  	0x02000008
#define TAG_PVI_REQ_DEVICE_STATE                            	0x02060000
#define TAG_PVI_DEVICE_STATE                                	0x02860000
#define TAG_PVI_DEVICE_CONNECTED                            	0x02860001
#define TAG_PVI_DEVICE_WORKING                              	0x02860002
#define TAG_PVI_DEVICE_IN_SERVICE                           	0x02860003
#define TAG_PVI_REQ_TYPE                                    	0x02000009
#define TAG_PVI_TYPE                                        	0x02800009
#define TAG_PVI_REQ_LAND_CODE                               	0x02000010
#define TAG_PVI_LAND_CODE                                   	0x02800010
#define TAG_PVI_REQ_LAND_CODE_LIST                          	0x02000011
#define TAG_PVI_REQ_SET_LAND_CODE                           	0x02000012
#define TAG_PVI_LAND_CODE_LIST                              	0x02800011

#define TAG_PVI_UZK_VOLTAGE                                 	0x02800050
#define TAG_PVI_REQ_UZK_VOLTAGE                             	0x02000050
#define TAG_PVI_COS_PHI                                     	0x02800060
#define TAG_PVI_REQ_COS_PHI                                 	0x02000060
#define TAG_PVI_REQ_SET_COS_PHI                             	0x02000061
#define TAG_PVI_COS_PHI_VALUE                               	0x02000062
#define TAG_PVI_COS_PHI_IS_AKTIV                            	0x02000063
#define TAG_PVI_COS_PHI_EXCITED                             	0x02000064
#define TAG_PVI_VOLTAGE_MONITORING                          	0x02800070
#define TAG_PVI_REQ_VOLTAGE_MONITORING                      	0x02000070
#define TAG_PVI_REQ_SET_VOLTAGE_MONITORING                  	0x02000071
#define TAG_PVI_VOLTAGE_MONITORING_THRESHOLD_TOP            	0x02000072
#define TAG_PVI_VOLTAGE_MONITORING_THRESHOLD_BOTTOM         	0x02000073
#define TAG_PVI_VOLTAGE_MONITORING_SLOPE_UP                 	0x02000074
#define TAG_PVI_VOLTAGE_MONITORING_SLOPE_DOWN               	0x02000075
#define TAG_PVI_FREQUENCY_UNDER_OVER                        	0x02800080
#define TAG_PVI_REQ_FREQUENCY_UNDER_OVER                    	0x02000080
#define TAG_PVI_SET_FREQUENCY_UNDER_OVER                    	0x02800081
#define TAG_PVI_REQ_SET_FREQUENCY_UNDER_OVER                	0x02000081
#define TAG_PVI_FREQUENCY_UNDER                             	0x02000082
#define TAG_PVI_FREQUENCY_OVER                              	0x02000083
#define TAG_PVI_SET_SYSTEM_MODE                             	0x02800084
#define TAG_PVI_REQ_SET_SYSTEM_MODE                         	0x02000084
#define TAG_PVI_SYSTEM_MODE                                 	0x02800085
#define TAG_PVI_REQ_SYSTEM_MODE                             	0x02000085
#define TAG_PVI_SET_POWER_MODE                              	0x02800086
#define TAG_PVI_REQ_SET_POWER_MODE                          	0x02000086
#define TAG_PVI_POWER_MODE                                  	0x02800087
#define TAG_PVI_REQ_POWER_MODE                              	0x02000087
#define TAG_PVI_REQ_USED_STRING_COUNT                       	0x02000090
#define TAG_PVI_REQ_SET_USED_STRING_COUNT                   	0x02000091
#define TAG_PVI_USED_STRING_COUNT                           	0x02800090
#define TAG_PVI_REQ_DERATE_TO_POWER                         	0x02000092
#define TAG_PVI_DERATE_TO_POWER                             	0x02800092

#define TAG_PVI_TEMPERATURE                                 	0x02800100
#define TAG_PVI_REQ_TEMPERATURE                             	0x02000100
#define TAG_PVI_TEMPERATURE_COUNT                           	0x02800101
#define TAG_PVI_REQ_TEMPERATURE_COUNT                       	0x02000101
#define TAG_PVI_MAX_TEMPERATURE                             	0x02800102
#define TAG_PVI_REQ_MAX_TEMPERATURE                         	0x02000102
#define TAG_PVI_MIN_TEMPERATURE                             	0x02800103
#define TAG_PVI_REQ_MIN_TEMPERATURE                         	0x02000103

#define TAG_PVI_SERIAL_NUMBER                               	0x028ABC01
#define TAG_PVI_REQ_SERIAL_NUMBER                           	0x020ABC01
#define TAG_PVI_VERSION                                     	0x028ABC02
#define TAG_PVI_REQ_VERSION                                 	0x020ABC02
#define TAG_PVI_VERSION_MAIN                                	0x020ABC03
#define TAG_PVI_VERSION_PIC                                 	0x020ABC04
#define TAG_PVI_REQ_SET_RESET_GPIO                          	0x020ABC50
#define TAG_PVI_REQ_SET_POWEROFF_GPIO                       	0x020ABC51
#define TAG_PVI_REQ_SET_NIGHTSWITCH_GPIO                    	0x020ABC52
#define TAG_PVI_REQ_SET_PRE_GRID_CHARGE                     	0x020ABC60

#define TAG_PVI_AC_MAX_PHASE_COUNT                          	0x028AC000
#define TAG_PVI_AC_POWER                                    	0x028AC001
#define TAG_PVI_AC_VOLTAGE                                  	0x028AC002
#define TAG_PVI_AC_CURRENT                                  	0x028AC003
#define TAG_PVI_AC_APPARENTPOWER                            	0x028AC004
#define TAG_PVI_AC_REACTIVEPOWER                            	0x028AC005
#define TAG_PVI_AC_ENERGY_ALL                               	0x028AC006
#define TAG_PVI_AC_MAX_APPARENTPOWER                        	0x028AC007
#define TAG_PVI_AC_ENERGY_DAY                               	0x028AC008
#define TAG_PVI_AC_ENERGY_GRID_CONSUMPTION                  	0x028AC009

#define TAG_PVI_REQ_AC_MAX_PHASE_COUNT                      	0x020AC000
#define TAG_PVI_REQ_AC_POWER                                	0x020AC001
#define TAG_PVI_REQ_AC_VOLTAGE                              	0x020AC002
#define TAG_PVI_REQ_AC_CURRENT                              	0x020AC003
#define TAG_PVI_REQ_AC_APPARENTPOWER                        	0x020AC004
#define TAG_PVI_REQ_AC_REACTIVEPOWER                        	0x020AC005
#define TAG_PVI_REQ_AC_ENERGY_ALL                           	0x020AC006
#define TAG_PVI_REQ_AC_MAX_APPARENTPOWER                    	0x020AC007
#define TAG_PVI_REQ_AC_ENERGY_DAY                           	0x020AC008
#define TAG_PVI_REQ_AC_ENERGY_GRID_CONSUMPTION              	0x020AC009

#define TAG_PVI_DC_MAX_STRING_COUNT                         	0x028DC000
#define TAG_PVI_DC_POWER                                    	0x028DC001
#define TAG_PVI_DC_VOLTAGE                                  	0x028DC002
#define TAG_PVI_DC_CURRENT                                  	0x028DC003
#define TAG_PVI_DC_MAX_POWER                                	0x028DC004
#define TAG_PVI_DC_MAX_VOLTAGE                              	0x028DC005
#define TAG_PVI_DC_MIN_VOLTAGE                              	0x028DC006
#define TAG_PVI_DC_MAX_CURRENT                              	0x028DC007
#define TAG_PVI_DC_MIN_CURRENT                              	0x028DC008
#define TAG_PVI_DC_STRING_ENERGY_ALL                        	0x028DC009

#define TAG_PVI_REQ_DC_MAX_STRING_COUNT                     	0x020DC000
#define TAG_PVI_REQ_DC_POWER                                	0x020DC001
#define TAG_PVI_REQ_DC_VOLTAGE                              	0x020DC002
#define TAG_PVI_REQ_DC_CURRENT                              	0x020DC003
#define TAG_PVI_REQ_DC_MAX_POWER                            	0x020DC004
#define TAG_PVI_REQ_DC_MAX_VOLTAGE                          	0x020DC005
#define TAG_PVI_REQ_DC_MIN_VOLTAGE                          	0x020DC006
#define TAG_PVI_REQ_DC_MAX_CURRENT                          	0x020DC007
#define TAG_PVI_REQ_DC_MIN_CURRENT                          	0x020DC008
#define TAG_PVI_REQ_DC_STRING_ENERGY_ALL                    	0x020DC009

#define TAG_HA_REQ_DATAPOINT_LIST                           	0x09000001
#define TAG_HA_REQ_ACTUATOR_STATES                          	0x09000010
#define TAG_HA_REQ_ADD_ACTUATOR                             	0x09000020
#define TAG_HA_REQ_REMOVE_ACTUATOR                          	0x09000030
#define TAG_HA_REQ_COMMAND_ACTUATOR                         	0x09000040
#define TAG_HA_REQ_COMMAND                                  	0x09000041
#define TAG_HA_REQ_DESCRIPTIONS_CHANGE                      	0x09000050
#define TAG_HA_REQ_CONFIGURATION_CHANGE_COUNTER             	0x09000060
#define TAG_HA_CONFIGURATION_CHANGE_COUNTER                 	0x09800060

#define TAG_HA_DATAPOINT_LIST                               	0x09800001
#define TAG_HA_DATAPOINT                                    	0x09800002
#define TAG_HA_DATAPOINT_INDEX                              	0x09800003
#define TAG_HA_DATAPOINT_TYPE                               	0x09800004
#define TAG_HA_DATAPOINT_NAME                               	0x09800005
#define TAG_HA_DATAPOINT_STATE                              	0x09800011
#define TAG_HA_DATAPOINT_STATE_TIMESTAMP                    	0x09800013
#define TAG_HA_DATAPOINT_STATE_VALUE                        	0x09800014
#define TAG_HA_DATAPOINT_SUPPLY_QUALITY                     	0x09800015
#define TAG_HA_DATAPOINT_SIGNAL_QUALITY                     	0x09800016
#define TAG_HA_DATAPOINT_MODE                               	0x09800012
#define TAG_HA_DATAPOINT_DESCRIPTIONS                       	0x09800006
#define TAG_HA_DATAPOINT_DESCRIPTION                        	0x09800007
#define TAG_HA_DATAPOINT_DESCRIPTION_NAME                   	0x09800008
#define TAG_HA_DATAPOINT_DESCRIPTION_VALUE                  	0x09800009
#define TAG_HA_ACTUATOR_STATES                              	0x09800010
#define TAG_HA_ADD_ACTUATOR                                 	0x09800020
#define TAG_HA_REMOVE_ACTUATOR                              	0x09800030
#define TAG_HA_COMMAND_ACTUATOR                             	0x09800040
#define TAG_HA_DESCRIPTIONS_CHANGE                          	0x09800050
#define TAG_HA_REQ_DEVICE_STATE                             	0x09060000
#define TAG_HA_DEVICE_STATE                                 	0x09860000
#define TAG_HA_DEVICE_CONNECTED                             	0x09860001
#define TAG_HA_DEVICE_WORKING                               	0x09860002
#define TAG_HA_DEVICE_IN_SERVICE                            	0x09860003
#define TAG_HA_GENERAL_ERROR                                	0x09FFFFFF


#define TAG_SRV_REQ_IS_ONLINE                               	0x08000001
#define TAG_SRV_IS_ONLINE                                   	0x08800001
#define TAG_SRV_REQ_ADD_USER                                	0x08000002
#define TAG_SRV_ADD_USER                                    	0x08800002

#define TAG_SRV_GENERAL_ERROR                               	0x08FFFFFF


#define TAG_INFO_REQ_SERIAL_NUMBER                          	0x0A000001
#define TAG_INFO_REQ_PRODUCTION_DATE                        	0x0A000002
#define TAG_INFO_REQ_MODULES_SW_VERSIONS                    	0x0A000003
#define TAG_INFO_REQ_A35_SERIAL_NUMBER                      	0x0A000007
#define TAG_INFO_REQ_IP_ADDRESS                             	0x0A000008
#define TAG_INFO_REQ_SUBNET_MASK                            	0x0A000009
#define TAG_INFO_REQ_MAC_ADDRESS                            	0x0A00000A
#define TAG_INFO_REQ_GATEWAY                                	0x0A00000B
#define TAG_INFO_REQ_DNS                                    	0x0A00000C
#define TAG_INFO_REQ_DHCP_STATUS                            	0x0A00000D
#define TAG_INFO_REQ_TIME                                   	0x0A00000E
#define TAG_INFO_REQ_UTC_TIME                               	0x0A00000F
#define TAG_INFO_REQ_TIME_ZONE                              	0x0A000010
#define TAG_INFO_REQ_INFO                                   	0x0A000011
#define TAG_INFO_REQ_SET_IP_ADDRESS                         	0x0A000012
#define TAG_INFO_REQ_SET_SUBNET_MASK                        	0x0A000013
#define TAG_INFO_REQ_SET_DHCP_STATUS                        	0x0A000014
#define TAG_INFO_REQ_SET_GATEWAY                            	0x0A000015
#define TAG_INFO_REQ_SET_DNS                                	0x0A000016
#define TAG_INFO_REQ_SET_TIME_ZONE                          	0x0A000018
#define TAG_INFO_REQ_SW_RELEASE                             	0x0A000019

#define TAG_INFO_SERIAL_NUMBER                              	0x0A800001
#define TAG_INFO_PRODUCTION_DATE                            	0x0A800002
#define TAG_INFO_MODULES_SW_VERSIONS                        	0x0A800003
#define TAG_INFO_MODULE_SW_VERSION                          	0x0A800004
#define TAG_INFO_MODULE                                     	0x0A800005
#define TAG_INFO_VERSION                                    	0x0A800006
#define TAG_INFO_A35_SERIAL_NUMBER                          	0x0A800007
#define TAG_INFO_IP_ADDRESS                                 	0x0A800008
#define TAG_INFO_SUBNET_MASK                                	0x0A800009
#define TAG_INFO_MAC_ADDRESS                                	0x0A80000A
#define TAG_INFO_GATEWAY                                    	0x0A80000B
#define TAG_INFO_DNS                                        	0x0A80000C
#define TAG_INFO_DHCP_STATUS                                	0x0A80000D
#define TAG_INFO_TIME                                       	0x0A80000E
#define TAG_INFO_UTC_TIME                                   	0x0A80000F
#define TAG_INFO_TIME_ZONE                                  	0x0A800010
#define TAG_INFO_INFO                                       	0x0A800011
#define TAG_INFO_SET_IP_ADDRESS                             	0x0A800012
#define TAG_INFO_SET_SUBNET_MASK                            	0x0A800013
#define TAG_INFO_SET_DHCP_STATUS                            	0x0A800014
#define TAG_INFO_SET_GATEWAY                                	0x0A800015
#define TAG_INFO_SET_DNS                                    	0x0A800016
#define TAG_INFO_SET_TIME                                   	0x0A800017
#define TAG_INFO_SET_TIME_ZONE                              	0x0A800018
#define TAG_INFO_SW_RELEASE                                 	0x0A800019

#define TAG_INFO_GENERAL_ERROR                              	0x0AFFFFFF

#define TAG_EP_REQ_SWITCH_TO_GRID                           	0x0B000001
#define TAG_EP_REQ_SWITCH_TO_ISLAND                         	0x0B000002
#define TAG_EP_REQ_IS_READY_FOR_SWITCH                      	0x0B000003
#define TAG_EP_REQ_IS_GRID_CONNECTED                        	0x0B000004
#define TAG_EP_REQ_IS_ISLAND_GRID                           	0x0B000005
#define TAG_EP_REQ_IS_INVALID_STATE                         	0x0B000006
#define TAG_EP_REQ_IS_POSSIBLE                              	0x0B000007
#define TAG_EP_REQ_LEAVE_INVALID_STATE_TO_ISLAND            	0x0B000008
#define TAG_EP_REQ_LEAVE_INVALID_STATE_TO_GRID              	0x0B000009

#define TAG_EP_SWITCH_TO_GRID                               	0x0B800001
#define TAG_EP_SWITCH_TO_ISLAND                             	0x0B800002
#define TAG_EP_IS_READY_FOR_SWITCH                          	0x0B800003
#define TAG_EP_IS_GRID_CONNECTED                            	0x0B800004
#define TAG_EP_IS_ISLAND_GRID                               	0x0B800005
#define TAG_EP_IS_INVALID_STATE                             	0x0B800006
#define TAG_EP_IS_POSSIBLE                                  	0x0B800007
#define TAG_EP_LEAVE_INVALID_STATE_TO_ISLAND                	0x0B800008
#define TAG_EP_LEAVE_INVALID_STATE_TO_GRID                  	0x0B800009

#define TAG_EP_GENERAL_ERROR                                	0x0BFFFFFF


#define TAG_DB_REQ_HISTORY_DATA_DAY                         	0x06000100
#define TAG_DB_REQ_HISTORY_TIME_START                       	0x06000101
#define TAG_DB_REQ_HISTORY_TIME_INTERVAL                    	0x06000102
#define TAG_DB_REQ_HISTORY_TIME_SPAN                        	0x06000103
#define TAG_DB_REQ_HISTORY_DATA_WEEK                        	0x06000200
#define TAG_DB_REQ_HISTORY_DATA_MONTH                       	0x06000300
#define TAG_DB_REQ_HISTORY_DATA_YEAR                        	0x06000400

#define TAG_DB_SUM_CONTAINER                                	0x06800010
#define TAG_DB_VALUE_CONTAINER                              	0x06800020
#define TAG_DB_GRAPH_INDEX                                  	0x06800001
#define TAG_DB_BAT_POWER_IN                                 	0x06800002
#define TAG_DB_BAT_POWER_OUT                                	0x06800003
#define TAG_DB_DC_POWER                                     	0x06800004
#define TAG_DB_GRID_POWER_IN                                	0x06800005
#define TAG_DB_GRID_POWER_OUT                               	0x06800006
#define TAG_DB_CONSUMPTION                                  	0x06800007
#define TAG_DB_PM_0_POWER                                   	0x06800008
#define TAG_DB_PM_1_POWER                                   	0x06800009
#define TAG_DB_BAT_CHARGE_LEVEL                             	0x0680000A
#define TAG_DB_BAT_CYCLE_COUNT                              	0x0680000B
#define TAG_DB_CONSUMED_PRODUCTION                          	0x0680000C
#define TAG_DB_AUTARKY                                      	0x0680000D

#define TAG_DB_HISTORY_DATA_DAY                             	0x06800100
#define TAG_DB_HISTORY_DATA_WEEK                            	0x06800200
#define TAG_DB_HISTORY_DATA_MONTH                           	0x06800300
#define TAG_DB_HISTORY_DATA_YEAR                            	0x06800400

#define TAG_DB_REQ_SYNC_HIST                                	0x06000500
#define TAG_DB_SYNC_HIST                                    	0x06800500
#define TAG_DB_REQ_VACUUM_HIST                              	0x06000501
#define TAG_DB_VACUUM_HIST                                  	0x06800501
#define TAG_DB_REQ_SYNC_BPU                                 	0x06000502
#define TAG_DB_SYNC_BPU                                     	0x06800502
#define TAG_DB_REQ_VACUUM_BPU                               	0x06000503
#define TAG_DB_VACUUM_BPU                                   	0x06800503
#define TAG_DB_REQ_SYNC_DCB                                 	0x06000504
#define TAG_DB_SYNC_DCB                                     	0x06800504
#define TAG_DB_REQ_VACUUM_DBC                               	0x06000505
#define TAG_DB_VACUUM_DCB                                   	0x06800505
#define TAG_DB_REQ_SYNC_BPU_CONF                            	0x06000506
#define TAG_DB_SYNC_BPU_CONF                                	0x06800506
#define TAG_DB_REQ_VACUUM_BPU_CONF                          	0x06000507
#define TAG_DB_VACUUM_BPU_CONF                              	0x06800507
#define TAG_DB_REQ_SYNC_DCB_CONF                            	0x06000508
#define TAG_DB_SYNC_DCB_CONF                                	0x06800508
#define TAG_DB_REQ_VACUUM_DBC_CONF                          	0x06000509
#define TAG_DB_VACUUM_DCB_CONF                              	0x06800509
#define TAG_DB_REQ_SYNC_WALLBOX                             	0x0600050A
#define TAG_DB_SYNC_WALLBOX                                 	0x0680050A
#define TAG_DB_REQ_VACUUM_WALLBOX                           	0x0600050B
#define TAG_DB_VACUUM_WALLBOX                               	0x0680050B
#define TAG_DB_REQ_SYNC_PV_DEBUG                            	0x0600050C
#define TAG_DB_SYNC_PV_DEBUG                                	0x0680050C
#define TAG_DB_REQ_VACUUM_PV_DEBUG                          	0x0600050D
#define TAG_DB_VACUUM_PV_DEBUG                              	0x0680050D
#define TAG_DB_REQ_SYNC_CONFIG                              	0x0600050E
#define TAG_DB_SYNC_CONFIG                                  	0x0680050E
#define TAG_DB_REQ_VACUUM_CONFIG                            	0x0600050F
#define TAG_DB_VACUUM_CONFIG                                	0x0680050F
#define TAG_DB_REQ_SET_SYNC_TIME                            	0x06000510
#define TAG_DB_SET_SYNC_TIME                                	0x06800510

#define TAG_DB_PAR_TIME_MIN                                 	0x06B00000
#define TAG_DB_PAR_TIME_MAX                                 	0x06B00001
#define TAG_DB_PARAM_ROW                                    	0x06B00002
#define TAG_DB_PARAM_COLUMN                                 	0x06B00003
#define TAG_DB_PARAM_INDEX                                  	0x06B00004
#define TAG_DB_PARAM_VALUE                                  	0x06B00005
#define TAG_DB_PARAM_MAX_ROWS                               	0x06B00006
#define TAG_DB_PARAM_TIME                                   	0x06B00007
#define TAG_DB_PARAM_VERSION                                	0x06B00008
#define TAG_DB_PARAM_HEADER                                 	0x06B00009







#define TAG_SYS_REQ_SYSTEM_REBOOT                           	0x0C000001
#define TAG_SYS_SYSTEM_REBOOT                               	0x0C800001
#define TAG_SYS_REQ_IS_SYSTEM_REBOOTING                     	0x0C000002
#define TAG_SYS_IS_SYSTEM_REBOOTING                         	0x0C800002
#define TAG_SYS_REQ_RESTART_APPLICATION                     	0x0C000003
#define TAG_SYS_RESTART_APPLICATION                         	0x0C800003
#define TAG_SYS_REQ_SCRIPT_FILE_LIST                        	0x0C000010
#define TAG_SYS_SCRIPT_FILE_LIST                            	0x0C800010
#define TAG_SYS_SCRIPT_FILE                                 	0x0C800011
#define TAG_SYS_REQ_EXECUTE_SCRIPT                          	0x0C000015
#define TAG_SYS_EXECUTE_SCRIPT                              	0x0C800015

#define TAG_SYS_GENERAL_ERROR                               	0x0CFFFFFF

#define TAG_UM_REQ_UPDATE_STATUS                            	0x0D000001
#define TAG_UM_UPDATE_STATUS                                	0x0D800001
#define TAG_UM_REQ_UPDATE_DCDC                              	0x0D000002
#define TAG_UM_UPDATE_DCDC                                  	0x0D800002
#define TAG_UM_REQ_CHECK_FOR_UPDATES                        	0x0D000003
#define TAG_UM_CHECK_FOR_UPDATES                            	0x0D800003

#define TAG_UM_GENERAL_ERROR                                	0x0DFFFFFF

#define TAG_WB_REQ_DATA                                     	0x0E040000
#define TAG_WB_INDEX                                        	0x0E040001
#define TAG_WB_DATA                                         	0x0E840000
#define TAG_WB_REQ_ENERGY_ALL                               	0x0E000001
#define TAG_WB_REQ_ENERGY_SOLAR                             	0x0E000002
#define TAG_WB_REQ_SOC                                      	0x0E000003
#define TAG_WB_REQ_STATUS                                   	0x0E000004
#define TAG_WB_REQ_ERROR_CODE                               	0x0E000005
#define TAG_WB_REQ_MODE                                     	0x0E000006
#define TAG_WB_REQ_APP_SOFTWARE                             	0x0E000007
#define TAG_WB_REQ_BOOTLOADER_SOFTWARE                      	0x0E000008
#define TAG_WB_REQ_HW_VERSION                               	0x0E000009
#define TAG_WB_REQ_FLASH_VERSION                            	0x0E00000A
#define TAG_WB_REQ_DEVICE_ID                                	0x0E00000B
#define TAG_WB_REQ_DEVICE_STATE                             	0x0E060000
#define TAG_WB_REQ_PM_POWER_L1                              	0x0E00000C
#define TAG_WB_REQ_PM_POWER_L2                              	0x0E00000D
#define TAG_WB_REQ_PM_POWER_L3                              	0x0E00000E
#define TAG_WB_REQ_PM_ACTIVE_PHASES                         	0x0E00000F
#define TAG_WB_REQ_PM_MODE                                  	0x0E000011
#define TAG_WB_REQ_PM_ENERGY_L1                             	0x0E000012
#define TAG_WB_REQ_PM_ENERGY_L2                             	0x0E000013
#define TAG_WB_REQ_PM_ENERGY_L3                             	0x0E000014
#define TAG_WB_REQ_PM_DEVICE_ID                             	0x0E000015
#define TAG_WB_REQ_PM_ERROR_CODE                            	0x0E000016
#define TAG_WB_REQ_PM_DEVICE_STATE                          	0x0E000029
#define TAG_WB_REQ_PM_FIRMWARE_VERSION                      	0x0E000017

#define TAG_WB_REQ_DIAG_DEVICE_ID                           	0x0E000018
#define TAG_WB_REQ_DIAG_BAT_CAPACITY                        	0x0E000019
#define TAG_WB_REQ_DIAG_USER_PARAM                          	0x0E00001A
#define TAG_WB_REQ_DIAG_MAX_CURRENT                         	0x0E00001B
#define TAG_WB_REQ_DIAG_PHASE_VOLTAGE                       	0x0E00001C
#define TAG_WB_REQ_DIAG_DISPLAY_SPEECH                      	0x0E00001D
#define TAG_WB_REQ_DIAG_DESIGN                              	0x0E00001E
#define TAG_WB_REQ_DIAG_INFOS                               	0x0E00001F
#define TAG_WB_REQ_DIAG_WARNINGS                            	0x0E000020
#define TAG_WB_REQ_DIAG_ERRORS                              	0x0E000021
#define TAG_WB_REQ_DIAG_TEMP_1                              	0x0E000022
#define TAG_WB_REQ_DIAG_TEMP_2                              	0x0E000023
#define TAG_WB_REQ_DIAG_CP_PEGEL                            	0x0E000024
#define TAG_WB_REQ_DIAG_PP_IN_A                             	0x0E000025
#define TAG_WB_REQ_DIAG_STATUS_DIODE                        	0x0E000026
#define TAG_WB_REQ_DIAG_DIG_IN_1                            	0x0E000027
#define TAG_WB_REQ_DIAG_DIG_IN_2                            	0x0E000028

#define TAG_WB_ENERGY_ALL                                   	0x0E800001
#define TAG_WB_ENERGY_SOLAR                                 	0x0E800002
#define TAG_WB_SOC                                          	0x0E800003
#define TAG_WB_STATUS                                       	0x0E800004
#define TAG_WB_ERROR_CODE                                   	0x0E800005
#define TAG_WB_MODE                                         	0x0E800006
#define TAG_WB_APP_SOFTWARE                                 	0x0E800007
#define TAG_WB_BOOTLOADER_SOFTWARE                          	0x0E800008
#define TAG_WB_HW_VERSION                                   	0x0E800009
#define TAG_WB_FLASH_VERSION                                	0x0E80000A
#define TAG_WB_DEVICE_ID                                    	0x0E80000B

#define TAG_WB_DEVICE_STATE                                 	0x0E860000
#define TAG_WB_DEVICE_CONNECTED                             	0x0E860001
#define TAG_WB_DEVICE_WORKING                               	0x0E860002
#define TAG_WB_DEVICE_IN_SERVICE                            	0x0E860003
#define TAG_WB_GENERAL_ERROR                                	0x0EFFFFFF

#define TAG_WB_PM_POWER_L1                                  	0x0E80000C
#define TAG_WB_PM_POWER_L2                                  	0x0E80000D
#define TAG_WB_PM_POWER_L3                                  	0x0E80000E
#define TAG_WB_PM_ACTIVE_PHASES                             	0x0E80000F
#define TAG_WB_PM_MODE                                      	0x0E800011
#define TAG_WB_PM_ENERGY_L1                                 	0x0E800012
#define TAG_WB_PM_ENERGY_L2                                 	0x0E800013
#define TAG_WB_PM_ENERGY_L3                                 	0x0E800014
#define TAG_WB_PM_DEVICE_ID                                 	0x0E800015
#define TAG_WB_PM_ERROR_CODE                                	0x0E800016
#define TAG_WB_PM_DEVICE_STATE                              	0x0E800029
#define TAG_WB_PM_DEVICE_STATE_CONNECTED                    	0x0E800030
#define TAG_WB_PM_DEVICE_STATE_WORKING                      	0x0E800031
#define TAG_WB_PM_DEVICE_STATE_IN_SERVICE                   	0x0E800032
#define TAG_WB_PM_FIRMWARE_VERSION                          	0x0E800017

#define TAG_WB_DIAG_DEVICE_ID                               	0x0E800018
#define TAG_WB_DIAG_BAT_CAPACITY                            	0x0E800019
#define TAG_WB_DIAG_USER_PARAM                              	0x0E80001A
#define TAG_WB_DIAG_MAX_CURRENT                             	0x0E80001B
#define TAG_WB_DIAG_PHASE_VOLTAGE                           	0x0E80001C
#define TAG_WB_DIAG_DISPLAY_SPEECH                          	0x0E80001D
#define TAG_WB_DIAG_DESIGN                                  	0x0E80001E
#define TAG_WB_DIAG_INFOS                                   	0x0E80001F
#define TAG_WB_DIAG_WARNINGS                                	0x0E800020
#define TAG_WB_DIAG_ERRORS                                  	0x0E800021
#define TAG_WB_DIAG_TEMP_1                                  	0x0E800022
#define TAG_WB_DIAG_TEMP_2                                  	0x0E800023
#define TAG_WB_DIAG_CP_PEGEL                                	0x0E800024
#define TAG_WB_DIAG_PP_IN_A                                 	0x0E800025
#define TAG_WB_DIAG_STATUS_DIODE                            	0x0E800026
#define TAG_WB_DIAG_DIG_IN_1                                	0x0E800027
#define TAG_WB_DIAG_DIG_IN_2                                	0x0E800028

#define TAG_WB_REQ_AVAILABLE_SOLAR_POWER                    	0x0E041000
#define TAG_WB_POWER                                        	0x0E041001
#define TAG_WB_STATUS_BIT                                   	0x0E041002
#define TAG_WB_AVAILABLE_SOLAR_POWER                        	0x0E841000
#define TAG_WB_REQ_SET_MODE                                 	0x0E000030
#define TAG_WB_MODE_PARAM_MODE                              	0x0E040031
#define TAG_WB_MODE_PARAM_MAX_CURRENT                       	0x0E040032
#define TAG_WB_SET_MODE                                     	0x0E000031

#define TAG_WB_REQ_SET_EXTERN                               	0x0E041010
#define TAG_WB_SET_EXTERN                                   	0x0E841010
#define TAG_WB_EXTERN_DATA                                  	0x0E042010
#define TAG_WB_EXTERN_DATA_LEN                              	0x0E042011

#define TAG_WB_REQ_EXTERN_DATA_SUN                          	0x0E041011
#define TAG_WB_REQ_EXTERN_DATA_NET                          	0x0E041012
#define TAG_WB_REQ_EXTERN_DATA_ALL                          	0x0E041013
#define TAG_WB_REQ_EXTERN_DATA_ALG                          	0x0E041014

#define TAG_WB_EXTERN_DATA_SUN                              	0x0E841011
#define TAG_WB_EXTERN_DATA_NET                              	0x0E841012
#define TAG_WB_EXTERN_DATA_ALL                              	0x0E841013
#define TAG_WB_EXTERN_DATA_ALG                              	0x0E841014

#define TAG_WB_REQ_SET_BAT_CAPACITY                         	0x0E041015
#define TAG_WB_REQ_SET_ENERGY_ALL                           	0x0E041016
#define TAG_WB_REQ_SET_ENERGY_SOLAR                         	0x0E041017
#define TAG_WB_REQ_SET_PARAM_1                              	0x0E041018
#define TAG_WB_REQ_SET_PARAM_2                              	0x0E041019
#define TAG_WB_REQ_SET_PW                                   	0x0E041020
#define TAG_WB_PARAM_USR                                    	0x0E042012
#define TAG_WB_PARAM_PW                                     	0x0E042013

#define TAG_WB_SET_BAT_CAPACITY                             	0x0E841015
#define TAG_WB_SET_ENERGY_ALL                               	0x0E841016
#define TAG_WB_SET_ENERGY_SOLAR                             	0x0E841017
#define TAG_WB_SET_PARAM_1                                  	0x0E841018
#define TAG_WB_SET_PARAM_2                                  	0x0E841019
#define TAG_WB_SET_PW                                       	0x0E841020
#define TAG_WB_REQ_PARAM_2                                  	0x0E04101A
#define TAG_WB_RSP_PARAM_2                                  	0x0E84101A
#define TAG_WB_REQ_PARAM_1                                  	0x0E04101B
#define TAG_WB_RSP_PARAM_1                                  	0x0E84101B



#define TAG_PTDB_REQ_SET_STD_PROPS                          	0x0F000001
#define TAG_PTDB_SET_STD_PROPS                              	0x0F800001

#define TAG_LED_REQ_SET_BAR_SWITCHED_ON_STATE               	0x10000001
#define TAG_LED_SET_BAR_SWITCHED_ON_STATE                   	0x10800001
#define TAG_LED_REQ_BAR_SWITCHED_ON_STATE                   	0x10000002
#define TAG_LED_BAR_SWITCHED_ON_STATE                       	0x10800002
#define TAG_LED_REQ_INTENSITY                               	0x10000003
#define TAG_LED_INTENSITY                                   	0x10800003
#define TAG_LED_REQ_SET_INTENSITY                           	0x10000004
#define TAG_LED_SET_INTENSITY                               	0x10800004
#define TAG_LED_REQ_COLOR                                   	0x10000005
#define TAG_LED_COLOR                                       	0x10800005
#define TAG_LED_REQ_SET_COLOR                               	0x10000006
#define TAG_LED_SET_COLOR                                   	0x10800006
#define TAG_LED_REQ_HW_INFO                                 	0x10000007
#define TAG_LED_HW_INFO                                     	0x10800007
#define TAG_LED_REQ_STORE_CONFIG                            	0x10000008
#define TAG_LED_CONFIG_STORED                               	0x10800009

#define TAG_LED_INDEX                                       	0x10860001
#define TAG_LED_RED                                         	0x10860002
#define TAG_LED_GREEN                                       	0x10860003
#define TAG_LED_BLUE                                        	0x10860004
#define TAG_LED_FW_VERSION                                  	0x10860005
#define TAG_LED_BL_VERSION                                  	0x10860006


#endif
