// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SHOOTERCOURSE_ShooterAnimInstance_generated_h
#error "ShooterAnimInstance.generated.h already included, missing '#pragma once' in ShooterAnimInstance.h"
#endif
#define SHOOTERCOURSE_ShooterAnimInstance_generated_h

#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_SPARSE_DATA
#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties);


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties);


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUShooterAnimInstance(); \
	friend struct Z_Construct_UClass_UShooterAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UShooterAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ShooterCourse"), NO_API) \
	DECLARE_SERIALIZER(UShooterAnimInstance)


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUShooterAnimInstance(); \
	friend struct Z_Construct_UClass_UShooterAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UShooterAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ShooterCourse"), NO_API) \
	DECLARE_SERIALIZER(UShooterAnimInstance)


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UShooterAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShooterAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShooterAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShooterAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UShooterAnimInstance(UShooterAnimInstance&&); \
	NO_API UShooterAnimInstance(const UShooterAnimInstance&); \
public:


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UShooterAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UShooterAnimInstance(UShooterAnimInstance&&); \
	NO_API UShooterAnimInstance(const UShooterAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShooterAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShooterAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShooterAnimInstance)


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ShooterCharacter() { return STRUCT_OFFSET(UShooterAnimInstance, ShooterCharacter); } \
	FORCEINLINE static uint32 __PPO__Speed() { return STRUCT_OFFSET(UShooterAnimInstance, Speed); } \
	FORCEINLINE static uint32 __PPO__bIsInAir() { return STRUCT_OFFSET(UShooterAnimInstance, bIsInAir); } \
	FORCEINLINE static uint32 __PPO__bIsAccelerating() { return STRUCT_OFFSET(UShooterAnimInstance, bIsAccelerating); }


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_12_PROLOG
#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_SPARSE_DATA \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_RPC_WRAPPERS \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_INCLASS \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_SPARSE_DATA \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
	ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHOOTERCOURSE_API UClass* StaticClass<class UShooterAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ShooterCourse_Source_ShooterCourse_ShooterAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
