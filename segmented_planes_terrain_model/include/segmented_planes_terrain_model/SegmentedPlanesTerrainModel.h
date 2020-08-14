//
// Created by rgrandia on 23.06.20.
//

#pragma once

#include <convex_plane_decomposition/PlanarRegion.h>
#include <ocs2_switched_model_interface/terrain/TerrainModel.h>

namespace switched_model {

class SegmentedPlanesTerrainModel : public switched_model::TerrainModel {
 public:
  SegmentedPlanesTerrainModel(convex_plane_decomposition::PlanarTerrain planarTerrain);

  TerrainPlane getLocalTerrainAtPositionInWorldAlongGravity(const vector3_t& positionInWorld) const override;

  ConvexTerrain getConvexTerrainAtPositionInWorld(const vector3_t& positionInWorld) const override;

  const SignedDistanceField* getSignedDistanceField() const override { return nullptr; }

  const convex_plane_decomposition::PlanarTerrain& planarTerrain() const { return planarTerrain_; }

 private:
  convex_plane_decomposition::PlanarTerrain planarTerrain_;
};

std::pair<const convex_plane_decomposition::PlanarRegion*, convex_plane_decomposition::CgalPoint2d> getPlanarRegionAtPositionInWorld(
    const vector3_t& positionInWorld, const std::vector<convex_plane_decomposition::PlanarRegion>& planarRegions);

}  // namespace switched_model
