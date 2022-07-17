# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: game.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='game.proto',
  package='GameMessage',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\ngame.proto\x12\x0bGameMessage\"\xa1\x03\n\tGameState\x12\x1c\n\x14isClosestObstacleBox\x18\x01 \x01(\x08\x12\x13\n\x0b\x63oinsNeeded\x18\x02 \x01(\x05\x12?\n\x0f\x63losestObstacle\x18\x03 \x01(\x0e\x32&.GameMessage.GameState.ObjectDirection\x12;\n\x0b\x63losestCoin\x18\x04 \x01(\x0e\x32&.GameMessage.GameState.ObjectDirection\x12<\n\x0c\x63losestEnemy\x18\x05 \x01(\x0e\x32&.GameMessage.GameState.ObjectDirection\x12?\n\x0f\x66inishDirection\x18\x06 \x01(\x0e\x32&.GameMessage.GameState.ObjectDirection\x12\x0e\n\x06reward\x18\x07 \x01(\x05\"T\n\x0fObjectDirection\x12\x0b\n\x07\x44\x45\x46\x41ULT\x10\x00\x12\x06\n\x02UP\x10\x01\x12\t\n\x05RIGHT\x10\x02\x12\x08\n\x04\x44OWN\x10\x03\x12\x08\n\x04LEFT\x10\x04\x12\r\n\tNOT_EXIST\x10\x05\"\xd1\x01\n\x06\x41\x63tion\x12:\n\rmoveDirection\x18\x01 \x01(\x0e\x32#.GameMessage.Action.ActionDirection\x12:\n\rshotDirection\x18\x02 \x01(\x0e\x32#.GameMessage.Action.ActionDirection\"O\n\x0f\x41\x63tionDirection\x12\x0b\n\x07\x44\x45\x46\x41ULT\x10\x00\x12\x06\n\x02UP\x10\x01\x12\t\n\x05RIGHT\x10\x02\x12\x08\n\x04\x44OWN\x10\x03\x12\x08\n\x04LEFT\x10\x04\x12\x08\n\x04IDLE\x10\x05\x32N\n\x11\x45xchangeGameState\x12\x39\n\x08\x45xchange\x12\x16.GameMessage.GameState\x1a\x13.GameMessage.Action\"\x00\x62\x06proto3')
)



_GAMESTATE_OBJECTDIRECTION = _descriptor.EnumDescriptor(
  name='ObjectDirection',
  full_name='GameMessage.GameState.ObjectDirection',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='DEFAULT', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='UP', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='RIGHT', index=2, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOWN', index=3, number=3,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='LEFT', index=4, number=4,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='NOT_EXIST', index=5, number=5,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=361,
  serialized_end=445,
)
_sym_db.RegisterEnumDescriptor(_GAMESTATE_OBJECTDIRECTION)

_ACTION_ACTIONDIRECTION = _descriptor.EnumDescriptor(
  name='ActionDirection',
  full_name='GameMessage.Action.ActionDirection',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='DEFAULT', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='UP', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='RIGHT', index=2, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOWN', index=3, number=3,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='LEFT', index=4, number=4,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='IDLE', index=5, number=5,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=578,
  serialized_end=657,
)
_sym_db.RegisterEnumDescriptor(_ACTION_ACTIONDIRECTION)


_GAMESTATE = _descriptor.Descriptor(
  name='GameState',
  full_name='GameMessage.GameState',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='isClosestObstacleBox', full_name='GameMessage.GameState.isClosestObstacleBox', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='coinsNeeded', full_name='GameMessage.GameState.coinsNeeded', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='closestObstacle', full_name='GameMessage.GameState.closestObstacle', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='closestCoin', full_name='GameMessage.GameState.closestCoin', index=3,
      number=4, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='closestEnemy', full_name='GameMessage.GameState.closestEnemy', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='finishDirection', full_name='GameMessage.GameState.finishDirection', index=5,
      number=6, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='reward', full_name='GameMessage.GameState.reward', index=6,
      number=7, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _GAMESTATE_OBJECTDIRECTION,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=28,
  serialized_end=445,
)


_ACTION = _descriptor.Descriptor(
  name='Action',
  full_name='GameMessage.Action',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='moveDirection', full_name='GameMessage.Action.moveDirection', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='shotDirection', full_name='GameMessage.Action.shotDirection', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _ACTION_ACTIONDIRECTION,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=448,
  serialized_end=657,
)

_GAMESTATE.fields_by_name['closestObstacle'].enum_type = _GAMESTATE_OBJECTDIRECTION
_GAMESTATE.fields_by_name['closestCoin'].enum_type = _GAMESTATE_OBJECTDIRECTION
_GAMESTATE.fields_by_name['closestEnemy'].enum_type = _GAMESTATE_OBJECTDIRECTION
_GAMESTATE.fields_by_name['finishDirection'].enum_type = _GAMESTATE_OBJECTDIRECTION
_GAMESTATE_OBJECTDIRECTION.containing_type = _GAMESTATE
_ACTION.fields_by_name['moveDirection'].enum_type = _ACTION_ACTIONDIRECTION
_ACTION.fields_by_name['shotDirection'].enum_type = _ACTION_ACTIONDIRECTION
_ACTION_ACTIONDIRECTION.containing_type = _ACTION
DESCRIPTOR.message_types_by_name['GameState'] = _GAMESTATE
DESCRIPTOR.message_types_by_name['Action'] = _ACTION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

GameState = _reflection.GeneratedProtocolMessageType('GameState', (_message.Message,), dict(
  DESCRIPTOR = _GAMESTATE,
  __module__ = 'game_pb2'
  # @@protoc_insertion_point(class_scope:GameMessage.GameState)
  ))
_sym_db.RegisterMessage(GameState)

Action = _reflection.GeneratedProtocolMessageType('Action', (_message.Message,), dict(
  DESCRIPTOR = _ACTION,
  __module__ = 'game_pb2'
  # @@protoc_insertion_point(class_scope:GameMessage.Action)
  ))
_sym_db.RegisterMessage(Action)



_EXCHANGEGAMESTATE = _descriptor.ServiceDescriptor(
  name='ExchangeGameState',
  full_name='GameMessage.ExchangeGameState',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=659,
  serialized_end=737,
  methods=[
  _descriptor.MethodDescriptor(
    name='Exchange',
    full_name='GameMessage.ExchangeGameState.Exchange',
    index=0,
    containing_service=None,
    input_type=_GAMESTATE,
    output_type=_ACTION,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_EXCHANGEGAMESTATE)

DESCRIPTOR.services_by_name['ExchangeGameState'] = _EXCHANGEGAMESTATE

# @@protoc_insertion_point(module_scope)
