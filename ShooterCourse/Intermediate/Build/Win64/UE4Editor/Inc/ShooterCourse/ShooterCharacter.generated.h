// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHOOTERCOURSE_ShooterCharacter_generated_h
#error "ShooterCharacter.generated.h already included, missing '#pragma once' in ShooterCharacter.h"
#endif
#define SHOOTERCOURSE_ShooterCharacter_generated_h

#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_SPARSE_DATA
#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_RPC_WRAPPERS
#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShooterCharacter(); \
	friend struct Z_Construct_UClass_AShooterCharacter_Statics; \
public: \
	DECLARE_CLASS(AShooterCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShooterCourse"), NO_API) \
	DECLARE_SERIALIZER(AShooterCharacter)


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAShooterCharacter(); \
	friend struct Z_Construct_UClass_AShooterCharacter_Statics; \
public: \
	DECLARE_CLASS(AShooterCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ShooterCourse"), NO_API) \
	DECLARE_SERIALIZER(AShooterCharacter)


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShooterCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShooterCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooterCharacter(AShooterCharacter&&); \
	NO_API AShooterCharacter(const AShooterCharacter&); \
public:


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooterCharacter(AShooterCharacter&&); \
	NO_API AShooterCharacter(const AShooterCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShooterCharacter)


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AShooterCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AShooterCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__BaseTurnRate() { return STRUCT_OFFSET(AShooterCharacter, BaseTurnRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpRate() { return STRUCT_OFFSET(AShooterCharacter, BaseLookUpRate); } \
	FORCEINLINE static uint32 __PPO__FireSound() { return STRUCT_OFFSET(AShooterCharacter, FireSound); } \
	FORCEINLINE static uint32 __PPO__MuzzleFlash() { return STRUCT_OFFSET(AShooterCharacter, MuzzleFlash); } \
	FORCEINLINE static uint32 __PPO__HipFireMontage() { return STRUCT_OFFSET(AShooterCharacter, HipFireMontage); } \
	FORCEINLINE static uint32 __PPO__ImpactParticles() { return STRUCT_OFFSET(AShooterCharacter, ImpactParticles); } \
	FORCEINLINE static uint32 __PPO__BeamParticles() { return STRUCT_OFFSET(AShooterCharacter, BeamParticles); }


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_9_PROLOG
#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_SPARSE_DATA \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_RPC_WRAPPERS \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_INCLASS \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_SPARSE_DATA \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_INCLASS_NO_PURE_DECLS \
	ShooterCourse_Source_ShooterCourse_ShooterCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHOOTERCOURSE_API UClass* StaticClass<class AShooterCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShooterCourse_Source_ShooterCourse_ShooterCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
